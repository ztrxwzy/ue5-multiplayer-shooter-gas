// Fill out your copyright notice in the Description page of Project Settings.


#include "PRAWeaponBase.h"
#include "ProtocolRiftArenaCharacter.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "PRAGameplayTags.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

// Sets default values
APRAWeaponBase::APRAWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;
	SetReplicateMovement(true);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(Root);

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePoint"));
	MuzzlePoint->SetupAttachment(WeaponMesh);
}

void APRAWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Weapon BeginPlay | Weapon: %s | Owner: %s | Authority: %d | Replicates: %d"),
		*GetNameSafe(this),
		*GetNameSafe(GetOwner()),
		HasAuthority(),
		GetIsReplicated());

	if(HasAuthority())
	{
		CurrentAmmo = MaxAmmo;
		NotifyAmmoChanged();
	}

}

void APRAWeaponBase::StartFire()
{
	UE_LOG(LogTemp, Warning, TEXT("StartFire | Weapon: %s | Owner: %s | Authority: %d"),
		*GetNameSafe(this),
		*GetNameSafe(GetOwner()),
		HasAuthority());

	AProtocolRiftArenaCharacter* OwningCharacter = GetOwningCharacter();
	if(!OwningCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no owning character."));
		return;
	}
	
	UCameraComponent* Camera = OwningCharacter->GetFollowCamera();
	if(!Camera)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no follow camera."));
		return;
	}

	const FVector TraceStart = Camera->GetComponentLocation();
	const FVector TraceDirection = Camera->GetForwardVector();
	if(HasAuthority())
	{
		TryFire(TraceStart, TraceDirection);
	}

	if(!HasAuthority())
	{
		ServerStartFire(TraceStart, TraceDirection);
	}
}

void APRAWeaponBase::StopFire()
{
	// For a hitscan weapon, we might not need to do anything here, but for a projectile weapon, we would stop firing projectiles.
}

void APRAWeaponBase::Fire()
{
	AProtocolRiftArenaCharacter* OwningCharacter = GetOwningCharacter();
	if(!OwningCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no owning character."));
		return;
	}

	UCameraComponent* Camera = OwningCharacter->GetFollowCamera();
	if(!Camera)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no follow camera."));
		return;
	}

	const FVector TraceStart = Camera->GetComponentLocation();
	const FVector TraceDistance = Camera->GetForwardVector();

	FireTrace(TraceStart, TraceDistance);
}

void APRAWeaponBase::FireTrace(const FVector& TraceStart, const FVector& TraceDirection)
{
	if(!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: not authority."));
		return;
	}

	AProtocolRiftArenaCharacter* OwningCharacter = GetOwningCharacter();
	if (!OwningCharacter)
	{	
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no owning character."));
		return;
	}

	const FVector TraceEnd = TraceStart + (TraceDirection * TraceRange);

	FHitResult HitResult;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(OwningCharacter);
	QueryParams.bTraceComplex = true;
	QueryParams.bReturnPhysicalMaterial = true;

	const bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
	UE_LOG(LogTemp, Warning, TEXT("Trace Hit Details | Actor: %s | Component: %s | ActorClass: %s | ComponentClass: %s | PhysMat: %s | SurfaceType: %d"),
		*GetNameSafe(HitResult.GetActor()),
		*GetNameSafe(HitResult.GetComponent()),
		*GetNameSafe(HitResult.GetActor() ? HitResult.GetActor()->GetClass() : nullptr),
		*GetNameSafe(HitResult.GetComponent() ? HitResult.GetComponent()->GetClass() : nullptr),
		*GetNameSafe(HitResult.PhysMaterial.Get()),
		static_cast<int32>(UGameplayStatics::GetSurfaceType(HitResult))
	);

	const FVector DebugEnd = bHit ? HitResult.ImpactPoint : TraceEnd;
	DrawDebugLine(GetWorld(), TraceStart, DebugEnd, FColor::Red, false, 2.0f, 0, 2.0f);

	if (bHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 12, FColor::Green, false, 2.0f);
		UE_LOG(LogTemp, Log, TEXT("Server Weapon hit: %s"), *HitResult.GetActor()->GetName());
		ApplyDamageToHitActor(HitResult);
		ExecuteImpactGameplayCue(HitResult);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Server Weapon fire but hit nothing"));
	}
}

AProtocolRiftArenaCharacter* APRAWeaponBase::GetOwningCharacter() const
{
	return Cast<AProtocolRiftArenaCharacter>(GetOwner());
}

void APRAWeaponBase::ServerStartFire_Implementation(const FVector_NetQuantize TraceStart, const FVector_NetQuantizeNormal TraceDirection)
{
	UE_LOG(LogTemp, Warning, TEXT("ServerStartFire received | Weapon: %s | Owner: %s | Authority: %d"),
		*GetNameSafe(this),
		*GetNameSafe(GetOwner()),
		HasAuthority());

	TryFire(TraceStart, TraceDirection);
}

void APRAWeaponBase::ApplyDamageToHitActor(const FHitResult& HitResult)
{
	if (!HasAuthority())
	{
		return;
	}

	AActor* HitActor = HitResult.GetActor();
	if(!HitActor)
	{
		return;
	}

	if(!DamageEffect)
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageEffect not set on weapon."));
		return;
	}

	AProtocolRiftArenaCharacter* OwningCharacter = GetOwningCharacter();
	if(!OwningCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no owning character."));
		return;
	}

	UAbilitySystemComponent* SourceASC = OwningCharacter->GetAbilitySystemComponent();
	if(!SourceASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no ability system component."));
		return;
	}

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(HitActor);
	if(!TargetASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no target ability system component."));
		return;
	}

	FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	EffectContext.AddHitResult(HitResult);

	const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffect, 1.0f, EffectContext);
	if(!SpecHandle.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no valid damage effect."));
		return;
	}

	SpecHandle.Data->SetSetByCallerMagnitude(PRAGameplayTags::Data_Damage(), Damage);

	SourceASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),TargetASC);

	UE_LOG(LogTemp, Warning, TEXT("Applied GAS damage | Source: %s | Target: %s | Damage: %.1f"),
		*GetNameSafe(OwningCharacter),
		*GetNameSafe(HitActor),
		Damage
	);
}

float APRAWeaponBase::GetFireInterval() const
{
	return FireRate > 0.0f ? 60.0f / FireRate : 0.0f;
}

bool APRAWeaponBase::CanFire() const
{
	const UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Fire failed: no valid world."));
		return false;
	}

	if (bIsReloading)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot fire: currently reloading."));
		return false;
	}

	if(!HasAmmo())
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot fire: no ammo."));
		return false;
	}

	const float CurrentTime = World->GetTimeSeconds();

	return CurrentTime >= LastFireTime + GetFireInterval();
}

void APRAWeaponBase::TryFire(const FVector& TraceStart, const FVector& TraceDirection)
{
	if(!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("TryFire called on client."));
		return;
	}

	if(!CanFire())
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire blocked | Ammo: %d/%d"), CurrentAmmo, MaxAmmo);
		return;
	}

	ConsumeAmmo();
	LastFireTime = GetWorld()->GetTimeSeconds();
	FireTrace(TraceStart, TraceDirection);
	MulticastPlayFireCosmetics();
	UE_LOG(LogTemp, Warning, TEXT("Weapon Fired | Weapon: %s | Owner: %s | Time: %.2f | Ammo: %d/%d"),
		*GetNameSafe(this),
		*GetNameSafe(GetOwner()),
		LastFireTime,
		CurrentAmmo,
		MaxAmmo
	);
}

void APRAWeaponBase::ConsumeAmmo()
{
	if (!HasAuthority())
	{
		return;
	}

	CurrentAmmo = FMath::Clamp(CurrentAmmo - 1, 0, MaxAmmo);
	NotifyAmmoChanged();
}

void APRAWeaponBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APRAWeaponBase, CurrentAmmo);
	DOREPLIFETIME(APRAWeaponBase, bIsReloading);
}

void APRAWeaponBase::OnRep_CurrentAmmo()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_CurrentAmmo | Weapon: %s | Owner: %s | CurrentAmmo: %d"),
		*GetNameSafe(this),
		*GetNameSafe(GetOwner()),
		CurrentAmmo
	);
	NotifyAmmoChanged();
}

void APRAWeaponBase::NotifyAmmoChanged()
{
	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
}

bool APRAWeaponBase::CanReload() const
{
	if(bIsReloading)
	{
		return false;
	}

	if(CurrentAmmo >= MaxAmmo)
	{
		return false;
	}

	AProtocolRiftArenaCharacter* OwningCharacter = GetOwningCharacter();
	if (!OwningCharacter)
	{
		return false;
	}
	if(OwningCharacter->IsDead())
	{
		return false;
	}

	return true;
}

void APRAWeaponBase::StartReload()
{
	if (HasAuthority())
	{
		if(CanReload())
		{
			bIsReloading = true;
			GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &APRAWeaponBase::FinishReload, ReloadDuration, false);
		}

		return;
	}

	ServerStartReload();
}

void APRAWeaponBase::ServerStartReload_Implementation()
{
	StartReload();
}

void APRAWeaponBase::FinishReload()
{
	if (!HasAuthority())
	{
		return;
	}
	bIsReloading = false;
	CurrentAmmo = MaxAmmo;
	NotifyAmmoChanged();
}

void APRAWeaponBase::OnRep_IsReloading()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_IsReloading | Weapon: %s | Owner: %s | IsReloading: %d"),
		*GetNameSafe(this),
		*GetNameSafe(GetOwner()),
		bIsReloading
	);
}

void APRAWeaponBase::PlayFireCosmetics()
{
	if (GetNetMode() == NM_DedicatedServer)
	{
		return;
	}
	if (MuzzleFlashEffect && MuzzlePoint)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(MuzzleFlashEffect, MuzzlePoint, NAME_None, FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, true);

	}

	if (FireSound && MuzzlePoint)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, MuzzlePoint->GetComponentLocation());
	}
}

void APRAWeaponBase::MulticastPlayFireCosmetics_Implementation()
{
	PlayFireCosmetics();
}

FGameplayTag APRAWeaponBase::DetermineImpactCueTag(const FHitResult& HitResult) const
{
	const EPhysicalSurface SurfaceType = UGameplayStatics::GetSurfaceType(HitResult);

	switch (SurfaceType)
	{
	case SurfaceType1:
		return PRAGameplayTags::GameplayCue_Weapon_Impact_Concrete();
	case SurfaceType2:
		return PRAGameplayTags::GameplayCue_Weapon_Impact_Glass();
	case SurfaceType3:
		return PRAGameplayTags::GameplayCue_Weapon_Impact_Metal();
	case SurfaceType4:
		return PRAGameplayTags::GameplayCue_Weapon_Impact_Wood();
	default:
		return PRAGameplayTags::GameplayCue_Weapon_Impact_Default();
	}
}

void APRAWeaponBase::ExecuteImpactGameplayCue(const FHitResult& HitResult)
{
	if (!HasAuthority())
	{
		return;
	}

	AProtocolRiftArenaCharacter* OwningCharacter = GetOwningCharacter();

	if(!OwningCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("Impact Cue failed: no owning character."));
		return;
	}

	UAbilitySystemComponent* SourceASC = OwningCharacter->GetAbilitySystemComponent();
	if (!SourceASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("Impact Cue failed: no source ASC"));
		return;
	}

	const FGameplayTag ImpactCueTag = DetermineImpactCueTag(HitResult);
	if (!ImpactCueTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Impact Cue failed: invalid cue tag"));
		return;
	}

	FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	EffectContext.AddHitResult(HitResult);

	FGameplayCueParameters CueParams;
	CueParams.Location = HitResult.ImpactPoint;
	CueParams.Normal = HitResult.ImpactNormal;
	CueParams.PhysicalMaterial = HitResult.PhysMaterial.Get();
	CueParams.EffectContext = EffectContext;
	CueParams.Instigator = OwningCharacter;
	CueParams.EffectCauser = this;
	CueParams.SourceObject = this;
	CueParams.TargetAttachComponent = HitResult.GetComponent();
	UE_LOG(LogTemp, Warning, TEXT("Executing Impact GameplayCue | Tag: %s | Location: %s | Normal: %s | PhysMat: %s"),
		*ImpactCueTag.ToString(),
		*CueParams.Location.ToString(),
		*CueParams.Normal.ToString(),
		*GetNameSafe(HitResult.PhysMaterial.Get())
	);

	SourceASC->ExecuteGameplayCue(ImpactCueTag, CueParams);
}
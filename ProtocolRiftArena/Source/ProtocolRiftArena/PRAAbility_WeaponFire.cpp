// Fill out your copyright notice in the Description page of Project Settings.


#include "PRAAbility_WeaponFire.h"
#include "ProtocolRiftArenaCharacter.h"
#include "PRAWeaponBase.h"
#include "PRAGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "DrawDebugHelpers.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Camera/CameraComponent.h"


UPRAAbility_WeaponFire::UPRAAbility_WeaponFire()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
}

void UPRAAbility_WeaponFire::ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData
)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AProtocolRiftArenaCharacter* Character = GetPRACharacterFromActorInfo();
	if (!Character)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	APRAWeaponBase* Weapon = Character->GetCurrentWeapon();
	if (!Weapon)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	if (!CanFireWeapon(Character, Weapon))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	FVector TraceStart;
	FVector TraceEnd;

	if (!BuildFireTrace(Character, Weapon, TraceStart, TraceEnd))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	if (!Weapon->ConsumeAmmo(1))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	Weapon->MarkFired();
	ExecuteFireGameplayCue(Character,Weapon);
	
	FHitResult HitResult;
	const bool bHit = PerformFireTrace(Character, Weapon, TraceStart, TraceEnd, HitResult);

	if (bHit)
	{
		ApplyDamageToHitActor(Character, Weapon, HitResult);
		ExecuteImpactGameplayCue(Character, Weapon, HitResult);
	}

	UE_LOG(LogTemp, Warning, TEXT(">>> GA_WeaponFire ACTIVATED | Avatar: %s | Authority: %d"),
	*GetNameSafe(GetAvatarActorFromActorInfo()),
	GetAvatarActorFromActorInfo() ? GetAvatarActorFromActorInfo()->HasAuthority() : false);
	
	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

bool UPRAAbility_WeaponFire::CanFireWeapon(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon) const
{
	if (!Character || !Weapon)
	{
		return false;
	}

	if (Character->IsDead())
	{
		return false;
	}
	
	const UAbilitySystemComponent* ASC = Character->GetAbilitySystemComponent();
	if (!ASC)
	{
		return false;
	}

	if (ASC->HasMatchingGameplayTag(PRAGameplayTags::State_Weapon_Reloading()))
	{
		return false;
	}

	if (!Weapon->HasAmmo())
	{
		return false;
	}

	const UWorld* World = Weapon->GetWorld();
	if (!World)
	{
		return false;
	}

	const float CurrentTime = World->GetTimeSeconds();
	return CurrentTime >= Weapon->GetLastFireTime() + Weapon->GetFireInterval();
}

bool UPRAAbility_WeaponFire::BuildFireTrace(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon, FVector& OutTraceStart, FVector& OutTraceEnd) const
{
	if (!Character || !Weapon)
	{
		return false;
	}

	UCameraComponent* Camera = Character->GetFollowCamera();
	if (!Camera) 
	{
		return false;
	}
	
	const FVector TraceDirection = Camera->GetForwardVector();
	
	OutTraceStart = Camera->GetComponentLocation();
	OutTraceEnd = OutTraceStart + (TraceDirection * Weapon->GetTraceRange());
	
	return true;
}

bool UPRAAbility_WeaponFire::PerformFireTrace(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon, const FVector& TraceStart, const FVector& TraceEnd, FHitResult& OutHitResult) const
{
	if (!Character || !Weapon)
	{
		return false;
	}
	
	UWorld* World = Character->GetWorld();
	if (!World)
	{
		return false;
	}
	
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Character);
	QueryParams.AddIgnoredActor(Weapon);
	QueryParams.bTraceComplex = true;
	QueryParams.bReturnPhysicalMaterial = true;
	
	const bool bHit = World->LineTraceSingleByChannel( OutHitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams );
	const FVector DebugEnd = bHit ? OutHitResult.ImpactPoint : TraceEnd;
	
	DrawDebugLine(World, TraceStart, DebugEnd, FColor::Red, false ,2.0f,0,2.0f);
	
	if (bHit)
	{
		DrawDebugSphere(World, OutHitResult.ImpactPoint, 10.0f, 12, FColor::Blue,false,2.0f);
	}
	
	return bHit;
}

void UPRAAbility_WeaponFire::ApplyDamageToHitActor(AProtocolRiftArenaCharacter* Character, APRAWeaponBase* Weapon, const FHitResult& HitResult)
{
	if (!Character||!Weapon)
	{
		return;
	}
	
	AActor* HitActor = HitResult.GetActor();
	if (!HitActor)
	{
		return;
	}
	
	TSubclassOf<UGameplayEffect> DamageEffect = Weapon->GetDamageEffect();
	if (!DamageEffect)
	{
		UE_LOG(LogTemp, Error, TEXT("DamageEffect is NULL"));
		return;
	}
	
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(HitActor);
	if (!TargetASC)
	{
		return;
	}
	
	UAbilitySystemComponent* SourceASC = Character->GetAbilitySystemComponent();
	if (!SourceASC)
	{
		return;
	}
	
	FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
	EffectContext.AddSourceObject(Weapon);
	EffectContext.AddHitResult(HitResult);
	
	const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffect, GetAbilityLevel(), EffectContext);
	
	if (!SpecHandle.IsValid())
	{
		return;
	}
	
	SpecHandle.Data->SetSetByCallerMagnitude(PRAGameplayTags::Data_Damage(),Weapon->GetDamage());
	
	SourceASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),TargetASC);
	
}

FGameplayTag UPRAAbility_WeaponFire::DetermineImpactCueTag(const FHitResult& HitResult) const
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

void UPRAAbility_WeaponFire::ExecuteImpactGameplayCue(
	AProtocolRiftArenaCharacter* Character,
	APRAWeaponBase* Weapon,
	const FHitResult& HitResult
)
{
	if (!Character || !Weapon)
	{
		return;
	}

	UAbilitySystemComponent* SourceASC = Character->GetAbilitySystemComponent();
	if (!SourceASC)
	{
		return;
	}

	const FGameplayTag ImpactCueTag = DetermineImpactCueTag(HitResult);
	if (!ImpactCueTag.IsValid())
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
	EffectContext.AddSourceObject(Weapon);
	EffectContext.AddHitResult(HitResult);

	FGameplayCueParameters CueParams;
	CueParams.Location = HitResult.ImpactPoint;
	CueParams.Normal = HitResult.ImpactNormal;
	CueParams.PhysicalMaterial = HitResult.PhysMaterial.Get();
	CueParams.EffectContext = EffectContext;
	CueParams.Instigator = Character;
	CueParams.EffectCauser = Weapon;
	CueParams.SourceObject = Weapon;
	CueParams.TargetAttachComponent = HitResult.GetComponent();

	SourceASC->ExecuteGameplayCue(ImpactCueTag, CueParams);
}

void UPRAAbility_WeaponFire::ExecuteFireGameplayCue(AProtocolRiftArenaCharacter* Character, APRAWeaponBase* Weapon)
{
	if (!Character || !Weapon)
	{
		return;
	}
	
	UAbilitySystemComponent* SourceASC = Character->GetAbilitySystemComponent();
	if (!SourceASC)
	{
		return;
	}
	
	USceneComponent* MuzzlePoint = Weapon->GetMuzzlePoint();
	if (!MuzzlePoint)
	{
		return;
	}
	
	FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
	EffectContext.AddSourceObject(Weapon);
	
	FGameplayCueParameters CueParams;
	CueParams.Location = MuzzlePoint->GetComponentLocation();
	CueParams.Normal = MuzzlePoint->GetForwardVector();
	CueParams.EffectContext = EffectContext;
	CueParams.Instigator = Character;
	CueParams.EffectCauser = Weapon;
	CueParams.SourceObject = Weapon;
	CueParams.TargetAttachComponent = MuzzlePoint;
	
	SourceASC->ExecuteGameplayCue(PRAGameplayTags::GameplayCue_Weapon_Fire(), CueParams);
}

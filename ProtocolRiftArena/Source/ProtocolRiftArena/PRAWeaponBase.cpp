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

AProtocolRiftArenaCharacter* APRAWeaponBase::GetOwningCharacter() const
{
	return Cast<AProtocolRiftArenaCharacter>(GetOwner());
}

float APRAWeaponBase::GetFireInterval() const
{
	return FireRate > 0.0f ? 60.0f / FireRate : 0.0f;
}

bool APRAWeaponBase::ConsumeAmmo(int32 Amount)
{
	if (!HasAuthority())
	{
		return false;
	}

	if (Amount <= 0)
	{
		return false;
	}

	if (CurrentAmmo < Amount)
	{
		return false;
	}

	CurrentAmmo = FMath::Clamp(CurrentAmmo - 1, 0, MaxAmmo);
	NotifyAmmoChanged();

	return true;
}

void APRAWeaponBase::MarkFired()
{
	if (!HasAuthority())
	{
		return;
	}

	if (UWorld* World = GetWorld())
	{
		LastFireTime = World->GetTimeSeconds();
	}
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




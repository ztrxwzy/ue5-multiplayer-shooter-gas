// Fill out your copyright notice in the Description page of Project Settings.


#include "PRAWeaponBase.h"
#include "ProtocolRiftArenaCharacter.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"

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
		FireTrace(TraceStart, TraceDirection);
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

	const bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);

	const FVector DebugEnd = bHit ? HitResult.ImpactPoint : TraceEnd;
	DrawDebugLine(GetWorld(), TraceStart, DebugEnd, FColor::Red, false, 2.0f, 0, 2.0f);

	if (bHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 12, FColor::Green, false, 2.0f);
		UE_LOG(LogTemp, Log, TEXT("Server Weapon hit: %s"), *HitResult.GetActor()->GetName());
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

	FireTrace(TraceStart, TraceDirection);
}


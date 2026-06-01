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

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(Root);

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePoint"));
	MuzzlePoint->SetupAttachment(WeaponMesh);
}

void APRAWeaponBase::StartFire()
{
	Fire();
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
	const FVector TraceEnd = TraceStart + (Camera->GetForwardVector() * TraceRange);

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
		UE_LOG(LogTemp, Log, TEXT("Weapon hit: %s"), *HitResult.GetActor()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Weapon fire but hit nothing"));
	}

}

AProtocolRiftArenaCharacter* APRAWeaponBase::GetOwningCharacter() const
{
	return Cast<AProtocolRiftArenaCharacter>(GetOwner());
}


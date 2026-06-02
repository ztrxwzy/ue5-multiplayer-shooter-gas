// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PRAWeaponBase.generated.h"

class USkeletalMeshComponent;
class AProtocolRiftArenaCharacter;

UCLASS()
class PROTOCOLRIFTARENA_API APRAWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APRAWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* MuzzlePoint;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Stats")
	float Damage = 25.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Stats")
	float FireRate = 600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Stats")
	float TraceRange = 10000.0f;
public:	
	UFUNCTION(BlueprintPure, Category = "Weapon|Stats")
	float GetDamage() const { return Damage; }
	UFUNCTION(BlueprintPure, Category = "Weapon|Stats")
	float GetFireRate() const { return FireRate; }
	UFUNCTION(BlueprintPure, Category = "Weapon|Stats")
	float GetTraceRange() const { return TraceRange; }
	UFUNCTION(BlueprintPure, Category = "Weapon")
	USceneComponent* GetMuzzlePoint() const { return MuzzlePoint; }
	UFUNCTION(BlueprintPure, Category = "Weapon")
	USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
	UFUNCTION(BlueprintCallable, Category = "Weapon|Fire")
	virtual void StartFire();
	UFUNCTION(BlueprintCallable, Category = "Weapon|Fire")
	virtual void StopFire();
	UFUNCTION(Server, Reliable)
	void ServerStartFire(FVector_NetQuantize TraceStart, FVector_NetQuantizeNormal TraceDirection);
	void FireTrace(const FVector& TraceStart, const FVector& TraceDirection);

protected: 
	virtual void Fire();
	AProtocolRiftArenaCharacter* GetOwningCharacter() const;
	virtual void BeginPlay() override;

};

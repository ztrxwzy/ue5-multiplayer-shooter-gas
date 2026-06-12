// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "PRAWeaponBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChangedSignature, int32, CurrentAmmo, int32, MaxAmmo);

class USkeletalMeshComponent;
class AProtocolRiftArenaCharacter;
class UGameplayEffect;
class UNiagaraSystem;
class USoundBase;

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Damage")
	float Damage = 25.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Stats")
	float FireRate = 600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Stats")
	float TraceRange = 10000.0f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapons|Fire")
	float LastFireTime = -999.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons|Ammo")
	int32 MaxAmmo = 30;
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_CurrentAmmo, BlueprintReadOnly, Category = "Weapons|Ammo")
	int32 CurrentAmmo;
	UPROPERTY(BlueprintAssignable, Category = "Weapon|Ammo")
	FOnAmmoChangedSignature OnAmmoChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Reload")
	float ReloadDuration = 1.5f;
	UPROPERTY(ReplicatedUsing = OnRep_IsReloading, BlueprintReadOnly, Category = "Weapon|Reload")
	bool bIsReloading;
	FTimerHandle ReloadTimerHandle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|FX")
	UNiagaraSystem* MuzzleFlashEffect;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|FX")
	USoundBase* FireSound;

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
	UFUNCTION(BlueprintPure, Category = "Weapon|Fire")
	float GetFireInterval() const;
	UFUNCTION(BlueprintPure, Category = "Weapon|Fire")
	bool CanFire() const;
	UFUNCTION(BlueprintPure, Category = "Weapon|Ammo")
	int32 GetMaxAmmo() const { return MaxAmmo; }
	UFUNCTION(BlueprintPure, Category = "Weapon|Ammo")
	int32 GetCurrentAmmo() const { return CurrentAmmo; }
	UFUNCTION(BlueprintCallable, Category = "Weapon|Ammo")
	bool HasAmmo() const { return CurrentAmmo > 0; }
	UFUNCTION()
	void OnRep_CurrentAmmo();
	UFUNCTION(BlueprintCallable, Category = "Weapon|Reload")
	void StartReload();
	UFUNCTION(BlueprintPure, Category = "Weapon|Reload")
	bool CanReload() const;
	UFUNCTION(BlueprintPure, Category = "Weapon|Reload")
	bool IsReloading() const { return bIsReloading; }
	UFUNCTION()
	void OnRep_IsReloading();
	UFUNCTION(Server,Reliable)
	void ServerStartReload();
	UFUNCTION(NetMulticast,Unreliable)
	void MulticastPlayFireCosmetics();

protected: 
	virtual void Fire();
	AProtocolRiftArenaCharacter* GetOwningCharacter() const;
	virtual void BeginPlay() override;
	void ApplyDamageToHitActor(const FHitResult& HitResult);
	void TryFire(const FVector& TraceStart, const FVector& TraceDirection);
	void ConsumeAmmo();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void NotifyAmmoChanged();
	void FinishReload();
	void PlayFireCosmetics();
	void ExecuteImpactGameplayCue(const FHitResult& HitResult);
	FGameplayTag DetermineImpactCueTag(const FHitResult& HitResult) const;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "PRAWeaponBase.generated.h"

class USkeletalMeshComponent;
class AProtocolRiftArenaCharacter;
class UGameplayEffect;
class UNiagaraSystem;
class USoundBase;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChangedSignature, int32, CurrentAmmo, int32, MaxAmmo);

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|FX")
	UNiagaraSystem* MuzzleFlashEffect;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|FX")
	USoundBase* FireSound;

public:	
	UFUNCTION(BlueprintPure, Category = "Weapon|Damage")
	TSubclassOf<UGameplayEffect> GetDamageEffect() const { return DamageEffect; }
	UFUNCTION(BlueprintPure,Category="Weapon|Damage")
	float GetDamage() const { return Damage; };
	UFUNCTION(BlueprintPure, Category = "Weapon|Stats")
	float GetTraceRange() const { return TraceRange; }
	UFUNCTION(BlueprintPure, Category = "Weapon|Fire")
	float GetFireInterval() const;
	UFUNCTION(BlueprintPure, Category = "Weapon|Ammo")
	int32 GetMaxAmmo() const { return MaxAmmo; }
	UFUNCTION(BlueprintPure, Category = "Weapon|Ammo")
	int32 GetCurrentAmmo() const { return CurrentAmmo; }
	UFUNCTION(BlueprintPure, Category = "Weapon|Fire")
	float GetLastFireTime() const { return LastFireTime; }
	UFUNCTION(BlueprintCallable, Category = "Weapon|Ammo")
	bool HasAmmo() const { return CurrentAmmo > 0; }
	UFUNCTION(BlueprintPure, Category="Weapon|Reload")
	float GetReloadDuration() const {return ReloadDuration; }
	UFUNCTION(BlueprintPure, Category="Weapon|Reload")
	bool CanReloadAmmoOnly() const;
	UFUNCTION()
	void OnRep_CurrentAmmo();
	bool ConsumeAmmo(int32 Amount = 1);
	void MarkFired();
	void RefillAmmo();
	
protected: 
	AProtocolRiftArenaCharacter* GetOwningCharacter() const;
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void NotifyAmmoChanged();
};

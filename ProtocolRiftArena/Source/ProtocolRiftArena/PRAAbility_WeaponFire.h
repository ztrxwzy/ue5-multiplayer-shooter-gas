// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PRAGameplayAbility.h"
#include "GameplayTagContainer.h"
#include "PRAAbility_WeaponFire.generated.h"

class AProtocolRiftArenaCharacter;
class APRAWeaponBase;
struct FHitResult;
UCLASS()
class PROTOCOLRIFTARENA_API UPRAAbility_WeaponFire : public UPRAGameplayAbility
{
	GENERATED_BODY()
public: 
	UPRAAbility_WeaponFire();
protected: 

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData) override;
	bool CanFireWeapon(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon) const;
	bool BuildFireTrace(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon, FVector& OutTraceStart, FVector& OutTraceEnd) const;
	bool PerformFireTrace(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weaon, const FVector& TraceStart, const FVector& TraceEnd, FHitResult& OutHitResult) const;
	void ApplyDamageToHitActor(AProtocolRiftArenaCharacter* Character, APRAWeaponBase* Weapon, const FHitResult& HitResult);
	void ExecuteImpactGameplayCue(AProtocolRiftArenaCharacter* Character, APRAWeaponBase* Weapon, const FHitResult& HitResult);
	FGameplayTag DetermineImpactCueTag(const FHitResult& HitResult) const;
};

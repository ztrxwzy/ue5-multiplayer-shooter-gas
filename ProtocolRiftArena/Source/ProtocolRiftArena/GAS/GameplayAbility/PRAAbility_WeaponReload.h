// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PRAGameplayAbility.h"
#include "PRAAbility_WeaponReload.generated.h"

class APRAWeaponBase;
class AProtocolRiftArenaCharacter;
class UGameplayEffect;

UCLASS()
class PROTOCOLRIFTARENA_API UPRAAbility_WeaponReload : public UPRAGameplayAbility
{
	GENERATED_BODY()
public:
	UPRAAbility_WeaponReload();
	
protected:	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Reload")
	TSubclassOf<UGameplayEffect> ReloadingStateEffect;
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData) 
	override;
	
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		bool bReplicateEndAbility, bool bWasCancelled) 
	override;
	
	bool CanReloadWeapon(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon) const;
	
	void CompleteReload();
	
	void ApplyReloadingState(AProtocolRiftArenaCharacter* Character);
	void RemoveReloadingState(AProtocolRiftArenaCharacter* Character);
	
private:
	FTimerHandle ReloadTimerHandle;
	FActiveGameplayEffectHandle ReloadingStateHandle;
	
};

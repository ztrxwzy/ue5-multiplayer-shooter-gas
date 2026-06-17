// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GameplayAbility/PRAAbility_WeaponReload.h"
#include "ProtocolRiftArenaCharacter.h"
#include "PRAWeaponBase.h"
#include "PRAGameplayTags.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "Engine/World.h"
#include "TimerManager.h"

UPRAAbility_WeaponReload::UPRAAbility_WeaponReload()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
}

void UPRAAbility_WeaponReload::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	AProtocolRiftArenaCharacter* Character = GetPRACharacterFromActorInfo();
	if (!Character)
	{
		return;
	}
	
	APRAWeaponBase* Weapon = Character->GetCurrentWeapon();
	if (!Weapon)
	{
		return;
	}
	
	if (!CanReloadWeapon(Character,Weapon))
	{
		EndAbility(Handle,ActorInfo,ActivationInfo,true,true);
		return;
	}
	
	ApplyReloadingState(Character);
	
	UWorld* World = Character->GetWorld();
	if (!World)
	{
		EndAbility(Handle,ActorInfo,ActivationInfo,true,true);
		return;
	}
	
	const float ReloadDuration = Weapon->GetReloadDuration();
	
	World->GetTimerManager().SetTimer(ReloadTimerHandle,this,&UPRAAbility_WeaponReload::CompleteReload,ReloadDuration,false);
	
	UE_LOG(LogTemp, Warning, TEXT("GA_WeaponReload started | Character: %s | Weapon: %s | Duration: %.2f"),
	*GetNameSafe(Character),
	*GetNameSafe(Weapon),
	ReloadDuration);
}

bool UPRAAbility_WeaponReload::CanReloadWeapon(const AProtocolRiftArenaCharacter* Character, const APRAWeaponBase* Weapon) const
{
	if (!Character||!Weapon)
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
	
	if (!Weapon->CanReloadAmmoOnly())
	{
		return false;
	}
	
	return true;
}

void UPRAAbility_WeaponReload::ApplyReloadingState(AProtocolRiftArenaCharacter* Character)
{
	if (!Character)
	{
		return;
	}
	
	UAbilitySystemComponent* ASC = Character->GetAbilitySystemComponent();
	if (!ASC || !ReloadingStateEffect)
	{
		UE_LOG(LogTemp,Warning,TEXT("GA_WeaponReload failed to apply ReloadingStateEffect."))
		return;
	}
	
	FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(ReloadingStateEffect,GetAbilityLevel(),EffectContext);
	if (!SpecHandle.IsValid())
	{
		return;
	}
	
	ReloadingStateHandle = ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void UPRAAbility_WeaponReload::RemoveReloadingState(AProtocolRiftArenaCharacter* Character)
{
	if (!Character)
	{
		return;
	}
	
	UAbilitySystemComponent* ASC = Character->GetAbilitySystemComponent();
	if (!ASC)
	{
		return;
	}
	
	if (ReloadingStateHandle.IsValid())
	{
		ASC->RemoveActiveGameplayEffect(ReloadingStateHandle);
		ReloadingStateHandle.Invalidate();
	}
}

void UPRAAbility_WeaponReload::CompleteReload()
{
	AProtocolRiftArenaCharacter* Character = GetPRACharacterFromActorInfo();
	if (!Character)
	{
		return;
	}
	
	APRAWeaponBase* Weapon = Character->GetCurrentWeapon();
	if (!Weapon)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}
	
	if (!Character->IsDead())
	{
		Weapon->RefillAmmo();
		UE_LOG(LogTemp, Warning, TEXT("GA_WeaponReload completed | Character: %s | Weapon: %s"),
			*GetNameSafe(Character),
			*GetNameSafe(Weapon)
		);
	}
	
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UPRAAbility_WeaponReload::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	AProtocolRiftArenaCharacter* Character = GetPRACharacterFromActorInfo();
	if (Character)
	{
		if (UWorld* World = Character->GetWorld())
		{
			World->GetTimerManager().ClearTimer(ReloadTimerHandle);
		}
		
		RemoveReloadingState(Character);
	}
	
	Super::EndAbility(Handle,ActorInfo,ActivationInfo,bReplicateEndAbility,bWasCancelled);
}

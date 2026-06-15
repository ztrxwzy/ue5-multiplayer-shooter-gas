// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtocolRiftArenaCharacter.h"
#include "PRAGameplayAbility.h"

UPRAGameplayAbility::UPRAGameplayAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;
}

AProtocolRiftArenaCharacter* UPRAGameplayAbility::GetPRACharacterFromActorInfo() const
{
	return Cast<AProtocolRiftArenaCharacter>(GetAvatarActorFromActorInfo());
}

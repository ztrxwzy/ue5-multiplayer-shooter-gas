// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "PRAGameplayAbility.generated.h"

class AProtocolRiftArenaCharacter;

UCLASS()
class PROTOCOLRIFTARENA_API UPRAGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPRAGameplayAbility();
protected:
	AProtocolRiftArenaCharacter* GetPRACharacterFromActorInfo() const;
};

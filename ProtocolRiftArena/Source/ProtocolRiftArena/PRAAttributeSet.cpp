// Fill out your copyright notice in the Description page of Project Settings.


#include "PRAAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UPRAAttributeSet::UPRAAttributeSet()
{

}



void UPRAAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UPRAAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPRAAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UPRAAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.0f);
	}
}

void UPRAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute == GetIncomingDamageAttribute())
	{
		const float LocalIncomingDamage = GetIncomingDamage();
		SetIncomingDamage(0.0f);
		if (LocalIncomingDamage > 0.0f)
		{
			const float OldHealth = GetHealth();
			const float NewHealth = FMath::Clamp(OldHealth - LocalIncomingDamage, 0.0f, GetMaxHealth());
			SetHealth(NewHealth);
			if (NewHealth <= 0.0f)
			{
				// Handle death logic here
				UE_LOG(LogTemp, Warning, TEXT("Character has died."));
			}
			UE_LOG(LogTemp, Warning, TEXT("GAS Damage Applied | OldHealth: %.1f | Damage: %.1f | NewHealth: %.1f"),
				OldHealth,
				LocalIncomingDamage,
				NewHealth
			);
		}

		return;
	}

	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}

	if(Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
	{
		SetMaxHealth(FMath::Max(GetMaxHealth(), 0.0f));
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
}

void UPRAAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPRAAttributeSet, Health, OldHealth);
}

void UPRAAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPRAAttributeSet, MaxHealth, OldMaxHealth);
}
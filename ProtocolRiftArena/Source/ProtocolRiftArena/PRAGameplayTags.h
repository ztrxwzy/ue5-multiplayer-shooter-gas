#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

namespace PRAGameplayTags
{
	FGameplayTag Data_Damage();
	FGameplayTag State_Death();
	FGameplayTag GameplayCue_Weapon_Impact_Default();
	FGameplayTag GameplayCue_Weapon_Impact_Concrete();
	FGameplayTag GameplayCue_Weapon_Impact_Glass();
	FGameplayTag GameplayCue_Weapon_Impact_Metal();
	FGameplayTag GameplayCue_Weapon_Impact_Wood();
}


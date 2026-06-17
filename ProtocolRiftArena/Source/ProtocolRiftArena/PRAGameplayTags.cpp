#include "PRAGameplayTags.h"

namespace PRAGameplayTags
{
	FGameplayTag Data_Damage()
	{
		static const FGameplayTag Tag = FGameplayTag::RequestGameplayTag(TEXT("Data.Damage"));
		return Tag;
	}

	FGameplayTag State_Death()
	{
		static const FGameplayTag Tag = FGameplayTag::RequestGameplayTag(TEXT("State.Death"));
		return Tag;
	}

	FGameplayTag GameplayCue_Weapon_Impact_Default()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayCue.Weapon.Impact.Default"));
	}

	FGameplayTag GameplayCue_Weapon_Impact_Concrete()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayCue.Weapon.Impact.Concrete"));
	}

	FGameplayTag GameplayCue_Weapon_Impact_Glass()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayCue.Weapon.Impact.Glass"));
	}

	FGameplayTag GameplayCue_Weapon_Impact_Metal()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayCue.Weapon.Impact.Metal"));
	}

	FGameplayTag GameplayCue_Weapon_Impact_Wood()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayCue.Weapon.Impact.Wood"));
	}

	FGameplayTag State_Weapon_Reloading()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("State.Weapon.Reloading"));
	}

	FGameplayTag GameplayCue_Weapon_Fire()
	{
		return FGameplayTag::RequestGameplayTag(TEXT("GameplayCue.Weapon.Fire"));
	}
}

#include "PRAGameplayTags.h"

namespace PRAGameplayTags
{
	FGameplayTag Data_Damage()
	{
		static const FGameplayTag Tag = FGameplayTag::RequestGameplayTag(TEXT("Data.Damage"));
		return Tag;
	}
}
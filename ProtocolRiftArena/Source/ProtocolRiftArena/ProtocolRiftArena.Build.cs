// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProtocolRiftArena : ModuleRules
{
	public ProtocolRiftArena(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProtocolRiftArena",
			"ProtocolRiftArena/Variant_Platforming",
			"ProtocolRiftArena/Variant_Platforming/Animation",
			"ProtocolRiftArena/Variant_Combat",
			"ProtocolRiftArena/Variant_Combat/AI",
			"ProtocolRiftArena/Variant_Combat/Animation",
			"ProtocolRiftArena/Variant_Combat/Gameplay",
			"ProtocolRiftArena/Variant_Combat/Interfaces",
			"ProtocolRiftArena/Variant_Combat/UI",
			"ProtocolRiftArena/Variant_SideScrolling",
			"ProtocolRiftArena/Variant_SideScrolling/AI",
			"ProtocolRiftArena/Variant_SideScrolling/Gameplay",
			"ProtocolRiftArena/Variant_SideScrolling/Interfaces",
			"ProtocolRiftArena/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

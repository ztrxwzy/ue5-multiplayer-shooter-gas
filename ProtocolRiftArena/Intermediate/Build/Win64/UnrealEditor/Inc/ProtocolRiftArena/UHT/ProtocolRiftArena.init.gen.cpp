// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProtocolRiftArena_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	PROTOCOLRIFTARENA_API UFunction* Z_Construct_UDelegateFunction_ProtocolRiftArena_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProtocolRiftArena;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProtocolRiftArena()
	{
		if (!Z_Registration_Info_UPackage__Script_ProtocolRiftArena.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_ProtocolRiftArena_OnEnemyDied__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ProtocolRiftArena",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xB59C106C,
			0x01B39713,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProtocolRiftArena.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ProtocolRiftArena.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProtocolRiftArena(Z_Construct_UPackage__Script_ProtocolRiftArena, TEXT("/Script/ProtocolRiftArena"), Z_Registration_Info_UPackage__Script_ProtocolRiftArena, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB59C106C, 0x01B39713));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

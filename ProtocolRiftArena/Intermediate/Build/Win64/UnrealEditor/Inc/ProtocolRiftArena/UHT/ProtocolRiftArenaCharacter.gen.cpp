// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProtocolRiftArenaCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeProtocolRiftArenaCharacter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
PROTOCOLRIFTARENA_API UClass* Z_Construct_UClass_APRAWeaponBase_NoRegister();
PROTOCOLRIFTARENA_API UClass* Z_Construct_UClass_AProtocolRiftArenaCharacter();
PROTOCOLRIFTARENA_API UClass* Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister();
PROTOCOLRIFTARENA_API UClass* Z_Construct_UClass_UPRAAttributeSet_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProtocolRiftArena();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AProtocolRiftArenaCharacter Function CanAim ******************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics
{
	struct ProtocolRiftArenaCharacter_eventCanAim_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanAim constinit property declarations ********************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanAim constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanAim Property Definitions *******************************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventCanAim_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventCanAim_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::PropPointers) < 2048);
// ********** End Function CanAim Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "CanAim", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::ProtocolRiftArenaCharacter_eventCanAim_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::ProtocolRiftArenaCharacter_eventCanAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execCanAim)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanAim();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function CanAim ********************************

// ********** Begin Class AProtocolRiftArenaCharacter Function CanSprint ***************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics
{
	struct ProtocolRiftArenaCharacter_eventCanSprint_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Sprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns true if the character is allowed to sprint right now */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if the character is allowed to sprint right now" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CanSprint constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanSprint constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanSprint Property Definitions ****************************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventCanSprint_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventCanSprint_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::PropPointers) < 2048);
// ********** End Function CanSprint Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "CanSprint", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::ProtocolRiftArenaCharacter_eventCanSprint_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::ProtocolRiftArenaCharacter_eventCanSprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execCanSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanSprint();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function CanSprint *****************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoAimEnd ****************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoAimEnd constinit property declarations ******************************
// ********** End Function DoAimEnd constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoAimEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoAimEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoAimEnd();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoAimEnd ******************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoAimStart **************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Aiming\n" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Aiming" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoAimStart constinit property declarations ****************************
// ********** End Function DoAimStart constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoAimStart", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoAimStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoAimStart();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoAimStart ****************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoCrouchEnd *************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Crouch" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoCrouchEnd constinit property declarations ***************************
// ********** End Function DoCrouchEnd constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoCrouchEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoCrouchEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoCrouchEnd();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoCrouchEnd ***************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoCrouchStart ***********************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Crouch" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoCrouchStart constinit property declarations *************************
// ********** End Function DoCrouchStart constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoCrouchStart", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoCrouchStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoCrouchStart();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoCrouchStart *************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoFireEnd ***************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoFireEnd constinit property declarations *****************************
// ********** End Function DoFireEnd constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoFireEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoFireEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoFireEnd();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoFireEnd *****************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoFireStart *************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Weapon\n" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Weapon" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoFireStart constinit property declarations ***************************
// ********** End Function DoFireStart constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoFireStart", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoFireStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoFireStart();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoFireStart ***************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoJumpEnd ***************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles jump pressed inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles jump pressed inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoJumpEnd constinit property declarations *****************************
// ********** End Function DoJumpEnd constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoJumpEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoJumpEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoJumpEnd();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoJumpEnd *****************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoJumpStart *************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles jump pressed inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles jump pressed inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoJumpStart constinit property declarations ***************************
// ********** End Function DoJumpStart constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoJumpStart", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoJumpStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoJumpStart();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoJumpStart ***************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoLook ******************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics
{
	struct ProtocolRiftArenaCharacter_eventDoLook_Parms
	{
		float Yaw;
		float Pitch;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles look inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles look inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoLook constinit property declarations ********************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Pitch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoLook constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoLook Property Definitions *******************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::NewProp_Yaw = { "Yaw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProtocolRiftArenaCharacter_eventDoLook_Parms, Yaw), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::NewProp_Pitch = { "Pitch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProtocolRiftArenaCharacter_eventDoLook_Parms, Pitch), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::NewProp_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::NewProp_Pitch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::PropPointers) < 2048);
// ********** End Function DoLook Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoLook", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::ProtocolRiftArenaCharacter_eventDoLook_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::ProtocolRiftArenaCharacter_eventDoLook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoLook)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Yaw);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Pitch);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoLook(Z_Param_Yaw,Z_Param_Pitch);
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoLook ********************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoMove ******************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics
{
	struct ProtocolRiftArenaCharacter_eventDoMove_Parms
	{
		float Right;
		float Forward;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles move inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles move inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoMove constinit property declarations ********************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Right;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Forward;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoMove constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoMove Property Definitions *******************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProtocolRiftArenaCharacter_eventDoMove_Parms, Right), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::NewProp_Forward = { "Forward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProtocolRiftArenaCharacter_eventDoMove_Parms, Forward), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::NewProp_Right,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::NewProp_Forward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::PropPointers) < 2048);
// ********** End Function DoMove Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoMove", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::ProtocolRiftArenaCharacter_eventDoMove_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::ProtocolRiftArenaCharacter_eventDoMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoMove)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Right);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Forward);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoMove(Z_Param_Right,Z_Param_Forward);
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoMove ********************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoSprintEnd *************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoSprintEnd constinit property declarations ***************************
// ********** End Function DoSprintEnd constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoSprintEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoSprintEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoSprintEnd();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoSprintEnd ***************************

// ********** Begin Class AProtocolRiftArenaCharacter Function DoSprintStart ***********************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DoSprintStart constinit property declarations *************************
// ********** End Function DoSprintStart constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "DoSprintStart", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execDoSprintStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoSprintStart();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function DoSprintStart *************************

// ********** Begin Class AProtocolRiftArenaCharacter Function GetAimPitch *************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics
{
	struct ProtocolRiftArenaCharacter_eventGetAimPitch_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAimPitch constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAimPitch constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAimPitch Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProtocolRiftArenaCharacter_eventGetAimPitch_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::PropPointers) < 2048);
// ********** End Function GetAimPitch Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "GetAimPitch", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::ProtocolRiftArenaCharacter_eventGetAimPitch_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::ProtocolRiftArenaCharacter_eventGetAimPitch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execGetAimPitch)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetAimPitch();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function GetAimPitch ***************************

// ********** Begin Class AProtocolRiftArenaCharacter Function GetAttributeSet *********************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics
{
	struct ProtocolRiftArenaCharacter_eventGetAttributeSet_Parms
	{
		UPRAAttributeSet* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ability System Interface */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ability System Interface" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAttributeSet constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAttributeSet constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAttributeSet Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ProtocolRiftArenaCharacter_eventGetAttributeSet_Parms, ReturnValue), Z_Construct_UClass_UPRAAttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::PropPointers) < 2048);
// ********** End Function GetAttributeSet Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "GetAttributeSet", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::ProtocolRiftArenaCharacter_eventGetAttributeSet_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::ProtocolRiftArenaCharacter_eventGetAttributeSet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execGetAttributeSet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPRAAttributeSet**)Z_Param__Result=P_THIS->GetAttributeSet();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function GetAttributeSet ***********************

// ********** Begin Class AProtocolRiftArenaCharacter Function HasMovementInput ********************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics
{
	struct ProtocolRiftArenaCharacter_eventHasMovementInput_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns true if the character is currently receiving movement input */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if the character is currently receiving movement input" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasMovementInput constinit property declarations **********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasMovementInput constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasMovementInput Property Definitions *********************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventHasMovementInput_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventHasMovementInput_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::PropPointers) < 2048);
// ********** End Function HasMovementInput Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "HasMovementInput", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::ProtocolRiftArenaCharacter_eventHasMovementInput_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::ProtocolRiftArenaCharacter_eventHasMovementInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execHasMovementInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasMovementInput();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function HasMovementInput **********************

// ********** Begin Class AProtocolRiftArenaCharacter Function IsAiming ****************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics
{
	struct ProtocolRiftArenaCharacter_eventIsAiming_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsAiming constinit property declarations ******************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsAiming constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsAiming Property Definitions *****************************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventIsAiming_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventIsAiming_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::PropPointers) < 2048);
// ********** End Function IsAiming Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "IsAiming", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::ProtocolRiftArenaCharacter_eventIsAiming_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::ProtocolRiftArenaCharacter_eventIsAiming_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execIsAiming)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAiming();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function IsAiming ******************************

// ********** Begin Class AProtocolRiftArenaCharacter Function OnRep_CurrentWeapon *****************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CurrentWeapon constinit property declarations *******************
// ********** End Function OnRep_CurrentWeapon constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "OnRep_CurrentWeapon", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execOnRep_CurrentWeapon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentWeapon();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function OnRep_CurrentWeapon *******************

// ********** Begin Class AProtocolRiftArenaCharacter Function OnRep_IsAiming **********************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_IsAiming constinit property declarations ************************
// ********** End Function OnRep_IsAiming constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "OnRep_IsAiming", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execOnRep_IsAiming)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_IsAiming();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function OnRep_IsAiming ************************

// ********** Begin Class AProtocolRiftArenaCharacter Function OnRep_IsSprinting *******************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_IsSprinting constinit property declarations *********************
// ********** End Function OnRep_IsSprinting constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "OnRep_IsSprinting", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execOnRep_IsSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_IsSprinting();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function OnRep_IsSprinting *********************

// ********** Begin Class AProtocolRiftArenaCharacter Function RefreshAimState *********************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshAimState constinit property declarations ***********************
// ********** End Function RefreshAimState constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "RefreshAimState", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execRefreshAimState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshAimState();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function RefreshAimState ***********************

// ********** Begin Class AProtocolRiftArenaCharacter Function RefreshSprintState ******************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Sprint" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-evaluates whether the character should currently be sprinting */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-evaluates whether the character should currently be sprinting" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSprintState constinit property declarations ********************
// ********** End Function RefreshSprintState constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "RefreshSprintState", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execRefreshSprintState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSprintState();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function RefreshSprintState ********************

// ********** Begin Class AProtocolRiftArenaCharacter Function ServerSetWantsToAim *****************
struct ProtocolRiftArenaCharacter_eventServerSetWantsToAim_Parms
{
	bool bNewAiming;
};
static FName NAME_AProtocolRiftArenaCharacter_ServerSetWantsToAim = FName(TEXT("ServerSetWantsToAim"));
void AProtocolRiftArenaCharacter::ServerSetWantsToAim(bool bNewAiming)
{
	ProtocolRiftArenaCharacter_eventServerSetWantsToAim_Parms Parms;
	Parms.bNewAiming=bNewAiming ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AProtocolRiftArenaCharacter_ServerSetWantsToAim);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerSetWantsToAim constinit property declarations *******************
	static void NewProp_bNewAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewAiming;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerSetWantsToAim constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerSetWantsToAim Property Definitions ******************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::NewProp_bNewAiming_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventServerSetWantsToAim_Parms*)Obj)->bNewAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::NewProp_bNewAiming = { "bNewAiming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventServerSetWantsToAim_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::NewProp_bNewAiming_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::NewProp_bNewAiming,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::PropPointers) < 2048);
// ********** End Function ServerSetWantsToAim Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "ServerSetWantsToAim", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::PropPointers), 
sizeof(ProtocolRiftArenaCharacter_eventServerSetWantsToAim_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ProtocolRiftArenaCharacter_eventServerSetWantsToAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execServerSetWantsToAim)
{
	P_GET_UBOOL(Z_Param_bNewAiming);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSetWantsToAim_Implementation(Z_Param_bNewAiming);
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function ServerSetWantsToAim *******************

// ********** Begin Class AProtocolRiftArenaCharacter Function ServerSetWantsToSprint **************
struct ProtocolRiftArenaCharacter_eventServerSetWantsToSprint_Parms
{
	bool bNewSprinting;
};
static FName NAME_AProtocolRiftArenaCharacter_ServerSetWantsToSprint = FName(TEXT("ServerSetWantsToSprint"));
void AProtocolRiftArenaCharacter::ServerSetWantsToSprint(bool bNewSprinting)
{
	ProtocolRiftArenaCharacter_eventServerSetWantsToSprint_Parms Parms;
	Parms.bNewSprinting=bNewSprinting ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AProtocolRiftArenaCharacter_ServerSetWantsToSprint);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ServerSetWantsToSprint constinit property declarations ****************
	static void NewProp_bNewSprinting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewSprinting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ServerSetWantsToSprint constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ServerSetWantsToSprint Property Definitions ***************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::NewProp_bNewSprinting_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventServerSetWantsToSprint_Parms*)Obj)->bNewSprinting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::NewProp_bNewSprinting = { "bNewSprinting", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventServerSetWantsToSprint_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::NewProp_bNewSprinting_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::NewProp_bNewSprinting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::PropPointers) < 2048);
// ********** End Function ServerSetWantsToSprint Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "ServerSetWantsToSprint", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::PropPointers), 
sizeof(ProtocolRiftArenaCharacter_eventServerSetWantsToSprint_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ProtocolRiftArenaCharacter_eventServerSetWantsToSprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execServerSetWantsToSprint)
{
	P_GET_UBOOL(Z_Param_bNewSprinting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSetWantsToSprint_Implementation(Z_Param_bNewSprinting);
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function ServerSetWantsToSprint ****************

// ********** Begin Class AProtocolRiftArenaCharacter Function SetAiming ***************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics
{
	struct ProtocolRiftArenaCharacter_eventSetAiming_Parms
	{
		bool bNewAiming;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAiming constinit property declarations *****************************
	static void NewProp_bNewAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewAiming;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAiming constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAiming Property Definitions ****************************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::NewProp_bNewAiming_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventSetAiming_Parms*)Obj)->bNewAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::NewProp_bNewAiming = { "bNewAiming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventSetAiming_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::NewProp_bNewAiming_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::NewProp_bNewAiming,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::PropPointers) < 2048);
// ********** End Function SetAiming Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "SetAiming", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::ProtocolRiftArenaCharacter_eventSetAiming_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::ProtocolRiftArenaCharacter_eventSetAiming_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execSetAiming)
{
	P_GET_UBOOL(Z_Param_bNewAiming);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAiming(Z_Param_bNewAiming);
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function SetAiming *****************************

// ********** Begin Class AProtocolRiftArenaCharacter Function SetSprinting ************************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics
{
	struct ProtocolRiftArenaCharacter_eventSetSprinting_Parms
	{
		bool bNewSprinting;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement | Sprint" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSprinting constinit property declarations **************************
	static void NewProp_bNewSprinting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewSprinting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSprinting constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSprinting Property Definitions *************************************
void Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::NewProp_bNewSprinting_SetBit(void* Obj)
{
	((ProtocolRiftArenaCharacter_eventSetSprinting_Parms*)Obj)->bNewSprinting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::NewProp_bNewSprinting = { "bNewSprinting", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ProtocolRiftArenaCharacter_eventSetSprinting_Parms), &Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::NewProp_bNewSprinting_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::NewProp_bNewSprinting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::PropPointers) < 2048);
// ********** End Function SetSprinting Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "SetSprinting", 	Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::ProtocolRiftArenaCharacter_eventSetSprinting_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::ProtocolRiftArenaCharacter_eventSetSprinting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execSetSprinting)
{
	P_GET_UBOOL(Z_Param_bNewSprinting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSprinting(Z_Param_bNewSprinting);
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function SetSprinting **************************

// ********** Begin Class AProtocolRiftArenaCharacter Function UpdateMovementSpeed *****************
struct Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateMovementSpeed constinit property declarations *******************
// ********** End Function UpdateMovementSpeed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AProtocolRiftArenaCharacter, nullptr, "UpdateMovementSpeed", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AProtocolRiftArenaCharacter::execUpdateMovementSpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateMovementSpeed();
	P_NATIVE_END;
}
// ********** End Class AProtocolRiftArenaCharacter Function UpdateMovementSpeed *******************

// ********** Begin Class AProtocolRiftArenaCharacter **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AProtocolRiftArenaCharacter;
UClass* AProtocolRiftArenaCharacter::GetPrivateStaticClass()
{
	using TClass = AProtocolRiftArenaCharacter;
	if (!Z_Registration_Info_UClass_AProtocolRiftArenaCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ProtocolRiftArenaCharacter"),
			Z_Registration_Info_UClass_AProtocolRiftArenaCharacter.InnerSingleton,
			StaticRegisterNativesAProtocolRiftArenaCharacter,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AProtocolRiftArenaCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister()
{
	return AProtocolRiftArenaCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple player-controllable third person character\n *  Implements a controllable orbiting camera\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ProtocolRiftArenaCharacter.h" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple player-controllable third person character\nImplements a controllable orbiting camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraRoot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseLookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mouse Look Input Action */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mouse Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Movement System */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement System" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement|Sprint" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchSpeed_MetaData[] = {
		{ "Category", "Movement|Crouch" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSprinting_MetaData[] = {
		{ "Category", "Movement|Sprint" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWantsToSprint_MetaData[] = {
		{ "Category", "Movement|Sprint" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastMovementInput_MetaData[] = {
		{ "Category", "Movement|Sprint" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StandingCameraRootOffset_MetaData[] = {
		{ "Category", "Camera|Root" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space camera root offset while standing  */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space camera root offset while standing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchingCameraRootOffset_MetaData[] = {
		{ "Category", "Camera|Root" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space camera root offset while crouching */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space camera root offset while crouching" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraRootInterpSpeed_MetaData[] = {
		{ "Category", "Camera|Root" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How fast the camera root follows its desired position */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How fast the camera root follows its desired position" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimWalkSpeed_MetaData[] = {
		{ "Category", "Movement|Aim" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Aiming feature\n" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Aiming feature" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWantsToAim_MetaData[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAiming_MetaData[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimPitch_MetaData[] = {
		{ "Category", "Movement|Aim" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimingCameraRootOffset_MetaData[] = {
		{ "Category", "Camera|Root" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space camera root offset while aiming */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space camera root offset while aiming" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchAimCameraRootOffset_MetaData[] = {
		{ "Category", "Camera|Root" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-space camera root offset while crouch-aiming */" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space camera root offset while crouch-aiming" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWeaponClass_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Weapon System\n" },
#endif
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Weapon System" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponAttachSocketName_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ability System Interface */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ability System Interface" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[] = {
		{ "Category", "GAS" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProtocolRiftArenaCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AProtocolRiftArenaCharacter constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MouseLookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CrouchAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CrouchSpeed;
	static void NewProp_bIsSprinting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSprinting;
	static void NewProp_bWantsToSprint_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWantsToSprint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastMovementInput;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StandingCameraRootOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CrouchingCameraRootOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraRootInterpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimWalkSpeed;
	static void NewProp_bWantsToAim_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWantsToAim;
	static void NewProp_bIsAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAiming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimPitch;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AimingCameraRootOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CrouchAimCameraRootOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultWeaponClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWeapon;
	static const UECodeGen_Private::FNamePropertyParams NewProp_WeaponAttachSocketName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AProtocolRiftArenaCharacter constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanAim"), .Pointer = &AProtocolRiftArenaCharacter::execCanAim },
		{ .NameUTF8 = UTF8TEXT("CanSprint"), .Pointer = &AProtocolRiftArenaCharacter::execCanSprint },
		{ .NameUTF8 = UTF8TEXT("DoAimEnd"), .Pointer = &AProtocolRiftArenaCharacter::execDoAimEnd },
		{ .NameUTF8 = UTF8TEXT("DoAimStart"), .Pointer = &AProtocolRiftArenaCharacter::execDoAimStart },
		{ .NameUTF8 = UTF8TEXT("DoCrouchEnd"), .Pointer = &AProtocolRiftArenaCharacter::execDoCrouchEnd },
		{ .NameUTF8 = UTF8TEXT("DoCrouchStart"), .Pointer = &AProtocolRiftArenaCharacter::execDoCrouchStart },
		{ .NameUTF8 = UTF8TEXT("DoFireEnd"), .Pointer = &AProtocolRiftArenaCharacter::execDoFireEnd },
		{ .NameUTF8 = UTF8TEXT("DoFireStart"), .Pointer = &AProtocolRiftArenaCharacter::execDoFireStart },
		{ .NameUTF8 = UTF8TEXT("DoJumpEnd"), .Pointer = &AProtocolRiftArenaCharacter::execDoJumpEnd },
		{ .NameUTF8 = UTF8TEXT("DoJumpStart"), .Pointer = &AProtocolRiftArenaCharacter::execDoJumpStart },
		{ .NameUTF8 = UTF8TEXT("DoLook"), .Pointer = &AProtocolRiftArenaCharacter::execDoLook },
		{ .NameUTF8 = UTF8TEXT("DoMove"), .Pointer = &AProtocolRiftArenaCharacter::execDoMove },
		{ .NameUTF8 = UTF8TEXT("DoSprintEnd"), .Pointer = &AProtocolRiftArenaCharacter::execDoSprintEnd },
		{ .NameUTF8 = UTF8TEXT("DoSprintStart"), .Pointer = &AProtocolRiftArenaCharacter::execDoSprintStart },
		{ .NameUTF8 = UTF8TEXT("GetAimPitch"), .Pointer = &AProtocolRiftArenaCharacter::execGetAimPitch },
		{ .NameUTF8 = UTF8TEXT("GetAttributeSet"), .Pointer = &AProtocolRiftArenaCharacter::execGetAttributeSet },
		{ .NameUTF8 = UTF8TEXT("HasMovementInput"), .Pointer = &AProtocolRiftArenaCharacter::execHasMovementInput },
		{ .NameUTF8 = UTF8TEXT("IsAiming"), .Pointer = &AProtocolRiftArenaCharacter::execIsAiming },
		{ .NameUTF8 = UTF8TEXT("OnRep_CurrentWeapon"), .Pointer = &AProtocolRiftArenaCharacter::execOnRep_CurrentWeapon },
		{ .NameUTF8 = UTF8TEXT("OnRep_IsAiming"), .Pointer = &AProtocolRiftArenaCharacter::execOnRep_IsAiming },
		{ .NameUTF8 = UTF8TEXT("OnRep_IsSprinting"), .Pointer = &AProtocolRiftArenaCharacter::execOnRep_IsSprinting },
		{ .NameUTF8 = UTF8TEXT("RefreshAimState"), .Pointer = &AProtocolRiftArenaCharacter::execRefreshAimState },
		{ .NameUTF8 = UTF8TEXT("RefreshSprintState"), .Pointer = &AProtocolRiftArenaCharacter::execRefreshSprintState },
		{ .NameUTF8 = UTF8TEXT("ServerSetWantsToAim"), .Pointer = &AProtocolRiftArenaCharacter::execServerSetWantsToAim },
		{ .NameUTF8 = UTF8TEXT("ServerSetWantsToSprint"), .Pointer = &AProtocolRiftArenaCharacter::execServerSetWantsToSprint },
		{ .NameUTF8 = UTF8TEXT("SetAiming"), .Pointer = &AProtocolRiftArenaCharacter::execSetAiming },
		{ .NameUTF8 = UTF8TEXT("SetSprinting"), .Pointer = &AProtocolRiftArenaCharacter::execSetSprinting },
		{ .NameUTF8 = UTF8TEXT("UpdateMovementSpeed"), .Pointer = &AProtocolRiftArenaCharacter::execUpdateMovementSpeed },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanAim, "CanAim" }, // 3424371901
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_CanSprint, "CanSprint" }, // 1513038061
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimEnd, "DoAimEnd" }, // 1688692768
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoAimStart, "DoAimStart" }, // 4019749272
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchEnd, "DoCrouchEnd" }, // 1454415708
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoCrouchStart, "DoCrouchStart" }, // 2875269798
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireEnd, "DoFireEnd" }, // 970556768
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoFireStart, "DoFireStart" }, // 127043865
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpEnd, "DoJumpEnd" }, // 1013457243
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoJumpStart, "DoJumpStart" }, // 3599227473
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoLook, "DoLook" }, // 4018500703
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoMove, "DoMove" }, // 3914857217
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintEnd, "DoSprintEnd" }, // 327933395
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_DoSprintStart, "DoSprintStart" }, // 3440152050
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAimPitch, "GetAimPitch" }, // 2542483398
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_GetAttributeSet, "GetAttributeSet" }, // 3619289873
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_HasMovementInput, "HasMovementInput" }, // 3008818497
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_IsAiming, "IsAiming" }, // 1473698128
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_CurrentWeapon, "OnRep_CurrentWeapon" }, // 395287858
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsAiming, "OnRep_IsAiming" }, // 1517529686
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_OnRep_IsSprinting, "OnRep_IsSprinting" }, // 777497957
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshAimState, "RefreshAimState" }, // 3532026327
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_RefreshSprintState, "RefreshSprintState" }, // 2284821106
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToAim, "ServerSetWantsToAim" }, // 2008137245
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_ServerSetWantsToSprint, "ServerSetWantsToSprint" }, // 3556470188
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetAiming, "SetAiming" }, // 2426678054
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_SetSprinting, "SetSprinting" }, // 2351677577
		{ &Z_Construct_UFunction_AProtocolRiftArenaCharacter_UpdateMovementSpeed, "UpdateMovementSpeed" }, // 3162148568
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProtocolRiftArenaCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics

// ********** Begin Class AProtocolRiftArenaCharacter Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CameraRoot = { "CameraRoot", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CameraRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraRoot_MetaData), NewProp_CameraRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_MouseLookAction = { "MouseLookAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, MouseLookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseLookAction_MetaData), NewProp_MouseLookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAction_MetaData), NewProp_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchAction = { "CrouchAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CrouchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchAction_MetaData), NewProp_CrouchAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimAction = { "AimAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, AimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimAction_MetaData), NewProp_AimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_FireAction = { "FireAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, FireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAction_MetaData), NewProp_FireAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchSpeed = { "CrouchSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CrouchSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchSpeed_MetaData), NewProp_CrouchSpeed_MetaData) };
void Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsSprinting_SetBit(void* Obj)
{
	((AProtocolRiftArenaCharacter*)Obj)->bIsSprinting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsSprinting = { "bIsSprinting", "OnRep_IsSprinting", (EPropertyFlags)0x0020080100020035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProtocolRiftArenaCharacter), &Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsSprinting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSprinting_MetaData), NewProp_bIsSprinting_MetaData) };
void Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToSprint_SetBit(void* Obj)
{
	((AProtocolRiftArenaCharacter*)Obj)->bWantsToSprint = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToSprint = { "bWantsToSprint", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProtocolRiftArenaCharacter), &Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToSprint_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWantsToSprint_MetaData), NewProp_bWantsToSprint_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_LastMovementInput = { "LastMovementInput", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, LastMovementInput), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastMovementInput_MetaData), NewProp_LastMovementInput_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_StandingCameraRootOffset = { "StandingCameraRootOffset", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, StandingCameraRootOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StandingCameraRootOffset_MetaData), NewProp_StandingCameraRootOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchingCameraRootOffset = { "CrouchingCameraRootOffset", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CrouchingCameraRootOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchingCameraRootOffset_MetaData), NewProp_CrouchingCameraRootOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CameraRootInterpSpeed = { "CameraRootInterpSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CameraRootInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraRootInterpSpeed_MetaData), NewProp_CameraRootInterpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimWalkSpeed = { "AimWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, AimWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimWalkSpeed_MetaData), NewProp_AimWalkSpeed_MetaData) };
void Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToAim_SetBit(void* Obj)
{
	((AProtocolRiftArenaCharacter*)Obj)->bWantsToAim = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToAim = { "bWantsToAim", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProtocolRiftArenaCharacter), &Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWantsToAim_MetaData), NewProp_bWantsToAim_MetaData) };
void Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsAiming_SetBit(void* Obj)
{
	((AProtocolRiftArenaCharacter*)Obj)->bIsAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsAiming = { "bIsAiming", "OnRep_IsAiming", (EPropertyFlags)0x0020080100020035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AProtocolRiftArenaCharacter), &Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAiming_MetaData), NewProp_bIsAiming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimPitch = { "AimPitch", nullptr, (EPropertyFlags)0x0020080000020035, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, AimPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimPitch_MetaData), NewProp_AimPitch_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimingCameraRootOffset = { "AimingCameraRootOffset", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, AimingCameraRootOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimingCameraRootOffset_MetaData), NewProp_AimingCameraRootOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchAimCameraRootOffset = { "CrouchAimCameraRootOffset", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CrouchAimCameraRootOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchAimCameraRootOffset_MetaData), NewProp_CrouchAimCameraRootOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_DefaultWeaponClass = { "DefaultWeaponClass", nullptr, (EPropertyFlags)0x0024080000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, DefaultWeaponClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APRAWeaponBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultWeaponClass_MetaData), NewProp_DefaultWeaponClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CurrentWeapon = { "CurrentWeapon", "OnRep_CurrentWeapon", (EPropertyFlags)0x0020080100020035, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, CurrentWeapon), Z_Construct_UClass_APRAWeaponBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeapon_MetaData), NewProp_CurrentWeapon_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_WeaponAttachSocketName = { "WeaponAttachSocketName", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, WeaponAttachSocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponAttachSocketName_MetaData), NewProp_WeaponAttachSocketName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, AbilitySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AProtocolRiftArenaCharacter, AttributeSet), Z_Construct_UClass_UPRAAttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeSet_MetaData), NewProp_AttributeSet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CameraRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_MouseLookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_FireAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsSprinting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToSprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_LastMovementInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_StandingCameraRootOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchingCameraRootOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CameraRootInterpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bWantsToAim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_bIsAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AimingCameraRootOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CrouchAimCameraRootOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_DefaultWeaponClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_CurrentWeapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_WeaponAttachSocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::NewProp_AttributeSet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::PropPointers) < 2048);
// ********** End Class AProtocolRiftArenaCharacter Property Definitions ***************************
UObject* (*const Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_ProtocolRiftArena,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AProtocolRiftArenaCharacter, IAbilitySystemInterface), false },  // 2722098046
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::ClassParams = {
	&AProtocolRiftArenaCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::Class_MetaDataParams)
};
void AProtocolRiftArenaCharacter::StaticRegisterNativesAProtocolRiftArenaCharacter()
{
	UClass* Class = AProtocolRiftArenaCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::Funcs));
}
UClass* Z_Construct_UClass_AProtocolRiftArenaCharacter()
{
	if (!Z_Registration_Info_UClass_AProtocolRiftArenaCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProtocolRiftArenaCharacter.OuterSingleton, Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AProtocolRiftArenaCharacter.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AProtocolRiftArenaCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_bIsSprinting(TEXT("bIsSprinting"));
	static FName Name_bIsAiming(TEXT("bIsAiming"));
	static FName Name_AimPitch(TEXT("AimPitch"));
	static FName Name_CurrentWeapon(TEXT("CurrentWeapon"));
	const bool bIsValid = true
		&& Name_bIsSprinting == ClassReps[(int32)ENetFields_Private::bIsSprinting].Property->GetFName()
		&& Name_bIsAiming == ClassReps[(int32)ENetFields_Private::bIsAiming].Property->GetFName()
		&& Name_AimPitch == ClassReps[(int32)ENetFields_Private::AimPitch].Property->GetFName()
		&& Name_CurrentWeapon == ClassReps[(int32)ENetFields_Private::CurrentWeapon].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AProtocolRiftArenaCharacter"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AProtocolRiftArenaCharacter);
AProtocolRiftArenaCharacter::~AProtocolRiftArenaCharacter() {}
// ********** End Class AProtocolRiftArenaCharacter ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h__Script_ProtocolRiftArena_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AProtocolRiftArenaCharacter, AProtocolRiftArenaCharacter::StaticClass, TEXT("AProtocolRiftArenaCharacter"), &Z_Registration_Info_UClass_AProtocolRiftArenaCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProtocolRiftArenaCharacter), 3461014168U) },
	};
}; // Z_CompiledInDeferFile_FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h__Script_ProtocolRiftArena_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h__Script_ProtocolRiftArena_3415956440{
	TEXT("/Script/ProtocolRiftArena"),
	Z_CompiledInDeferFile_FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h__Script_ProtocolRiftArena_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h__Script_ProtocolRiftArena_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

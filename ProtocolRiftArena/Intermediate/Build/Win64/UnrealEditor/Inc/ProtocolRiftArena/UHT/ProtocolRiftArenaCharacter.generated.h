// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProtocolRiftArenaCharacter.h"

#ifdef PROTOCOLRIFTARENA_ProtocolRiftArenaCharacter_generated_h
#error "ProtocolRiftArenaCharacter.generated.h already included, missing '#pragma once' in ProtocolRiftArenaCharacter.h"
#endif
#define PROTOCOLRIFTARENA_ProtocolRiftArenaCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APRAWeaponBase;
class UPRAAttributeSet;

// ********** Begin Delegate FOnCurrentWeaponChangedSignature **************************************
#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_24_DELEGATE \
PROTOCOLRIFTARENA_API void FOnCurrentWeaponChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnCurrentWeaponChangedSignature, APRAWeaponBase* NewWeapon);


// ********** End Delegate FOnCurrentWeaponChangedSignature ****************************************

// ********** Begin Class AProtocolRiftArenaCharacter **********************************************
#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ServerSetWantsToAim_Implementation(bool bNewAiming); \
	virtual void ServerSetWantsToSprint_Implementation(bool bNewSprinting); \
	DECLARE_FUNCTION(execIsDead); \
	DECLARE_FUNCTION(execGetAttributeSet); \
	DECLARE_FUNCTION(execGetCurrentWeapon); \
	DECLARE_FUNCTION(execOnRep_CurrentWeapon); \
	DECLARE_FUNCTION(execDoFireEnd); \
	DECLARE_FUNCTION(execDoFireStart); \
	DECLARE_FUNCTION(execServerSetWantsToAim); \
	DECLARE_FUNCTION(execOnRep_IsAiming); \
	DECLARE_FUNCTION(execGetAimPitch); \
	DECLARE_FUNCTION(execIsAiming); \
	DECLARE_FUNCTION(execRefreshAimState); \
	DECLARE_FUNCTION(execCanAim); \
	DECLARE_FUNCTION(execSetAiming); \
	DECLARE_FUNCTION(execDoAimEnd); \
	DECLARE_FUNCTION(execDoAimStart); \
	DECLARE_FUNCTION(execServerSetWantsToSprint); \
	DECLARE_FUNCTION(execOnRep_IsSprinting); \
	DECLARE_FUNCTION(execUpdateMovementSpeed); \
	DECLARE_FUNCTION(execDoCrouchEnd); \
	DECLARE_FUNCTION(execDoCrouchStart); \
	DECLARE_FUNCTION(execRefreshSprintState); \
	DECLARE_FUNCTION(execCanSprint); \
	DECLARE_FUNCTION(execHasMovementInput); \
	DECLARE_FUNCTION(execSetSprinting); \
	DECLARE_FUNCTION(execDoSprintEnd); \
	DECLARE_FUNCTION(execDoSprintStart); \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoReload);


#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics;
PROTOCOLRIFTARENA_API UClass* Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister();

#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProtocolRiftArenaCharacter(); \
	friend struct ::Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROTOCOLRIFTARENA_API UClass* ::Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AProtocolRiftArenaCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProtocolRiftArena"), Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister) \
	DECLARE_SERIALIZER(AProtocolRiftArenaCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AProtocolRiftArenaCharacter*>(this); } \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsSprinting=NETFIELD_REP_START, \
		bIsAiming, \
		AimPitch, \
		CurrentWeapon, \
		NETFIELD_REP_END=CurrentWeapon	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AProtocolRiftArenaCharacter(AProtocolRiftArenaCharacter&&) = delete; \
	AProtocolRiftArenaCharacter(const AProtocolRiftArenaCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProtocolRiftArenaCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProtocolRiftArenaCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AProtocolRiftArenaCharacter) \
	NO_API virtual ~AProtocolRiftArenaCharacter();


#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_32_PROLOG
#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_CALLBACK_WRAPPERS \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_INCLASS_NO_PURE_DECLS \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AProtocolRiftArenaCharacter;

// ********** End Class AProtocolRiftArenaCharacter ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

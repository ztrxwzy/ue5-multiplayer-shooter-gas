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

// ********** Begin Class AProtocolRiftArenaCharacter **********************************************
#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
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
	DECLARE_FUNCTION(execDoMove);


struct Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics;
PROTOCOLRIFTARENA_API UClass* Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister();

#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProtocolRiftArenaCharacter(); \
	friend struct ::Z_Construct_UClass_AProtocolRiftArenaCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROTOCOLRIFTARENA_API UClass* ::Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AProtocolRiftArenaCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProtocolRiftArena"), Z_Construct_UClass_AProtocolRiftArenaCharacter_NoRegister) \
	DECLARE_SERIALIZER(AProtocolRiftArenaCharacter)


#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AProtocolRiftArenaCharacter(AProtocolRiftArenaCharacter&&) = delete; \
	AProtocolRiftArenaCharacter(const AProtocolRiftArenaCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProtocolRiftArenaCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProtocolRiftArenaCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AProtocolRiftArenaCharacter) \
	NO_API virtual ~AProtocolRiftArenaCharacter();


#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_22_PROLOG
#define FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_INCLASS_NO_PURE_DECLS \
	FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AProtocolRiftArenaCharacter;

// ********** End Class AProtocolRiftArenaCharacter ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Videogames_ue5_multiplayer_shooter_gas_ProtocolRiftArena_Source_ProtocolRiftArena_ProtocolRiftArenaCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

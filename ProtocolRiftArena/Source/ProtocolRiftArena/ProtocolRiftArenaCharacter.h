// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ProtocolRiftArenaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class USceneComponent;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class AProtocolRiftArenaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* CameraRoot;

protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* CrouchAction;

	/** Movement System */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float WalkSpeed = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement|Sprint")
	float SprintSpeed = 800.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement|Crouch")
	float CrouchSpeed = 250.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Sprint")
	bool bIsSprinting = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Sprint")
	bool bWantsToSprint = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Sprint")
	FVector2D LastMovementInput = FVector2D::ZeroVector;
	/** World-space camera root offset while standing  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Root")
	FVector StandingCameraRootOffset = FVector(0.f, 0.f, 80.0f);
	/** World-space camera root offset while crouching */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Root")
	FVector CrouchingCameraRootOffset = FVector(0.f, 0.f, 35.0f);
	/** How fast the camera root follows its desired position */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Root")
	float CameraRootInterpSpeed = 10.0f;

public:

	/** Constructor */
	AProtocolRiftArenaCharacter();	

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override;

	/* Called when the character begins play */
	virtual void BeginPlay() override;

	/* Called every frame */
	virtual void Tick(float DeltaTime) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called when movement input is released */
	void StopMove();

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called when the character starts crouching */
	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

	/** Called when the character stops crouching */
	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

	/** Updates the camera root position */
	void UpdateCameraRoot(float DeltaTime);

public:

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoSprintStart();

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoSprintEnd();

	UFUNCTION(BlueprintCallable, Category = "Movement | Sprint")
	virtual void SetSprinting(bool bNewSprinting);

	/** Returns true if the character is currently receiving movement input */
	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual bool HasMovementInput() const;

	/** Returns true if the character is allowed to sprint right now */
	UFUNCTION(BlueprintCallable, Category = "Movement|Sprint")
	virtual bool CanSprint() const;

	/** Re-evaluates whether the character should currently be sprinting */
	UFUNCTION(BlueprintCallable, Category = "Movement|Sprint")
	virtual void RefreshSprintState();
	UFUNCTION(BlueprintCallable, Category = "Movement|Crouch")
	virtual void DoCrouchStart();
	UFUNCTION(BlueprintCallable, Category = "Movement|Crouch")
	virtual void DoCrouchEnd();
	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual void UpdateMovementSpeed();
public:

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};


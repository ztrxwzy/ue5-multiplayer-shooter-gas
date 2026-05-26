// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProtocolRiftArenaCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "ProtocolRiftArena.h"
#include "Components/SceneComponent.h"

AProtocolRiftArenaCharacter::AProtocolRiftArenaCharacter()
{

	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeedCrouched = CrouchSpeed;

	// Create a camera root component
	CameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraRoot"));
	CameraRoot->SetupAttachment(RootComponent);

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(CameraRoot);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AProtocolRiftArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProtocolRiftArenaCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AProtocolRiftArenaCharacter::StopMove);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AProtocolRiftArenaCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AProtocolRiftArenaCharacter::Look);

		//Sprinting
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AProtocolRiftArenaCharacter::DoSprintStart);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AProtocolRiftArenaCharacter::DoSprintEnd);

		//Crouch
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AProtocolRiftArenaCharacter::DoCrouchStart);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AProtocolRiftArenaCharacter::DoCrouchEnd);
	}
	else
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AProtocolRiftArenaCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(CameraRoot)
	{
		CameraRoot->SetUsingAbsoluteLocation(true);
		CameraRoot->SetWorldLocation(GetActorLocation() + StandingCameraRootOffset);
	}
}

void AProtocolRiftArenaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateCameraRoot(DeltaTime);
}

void AProtocolRiftArenaCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	LastMovementInput = Value.Get<FVector2D>();
	
	//Sprint depends on whether the character is currently receiving movement input
	RefreshSprintState();

	// route the input
	DoMove(LastMovementInput.X, LastMovementInput.Y);
}

void AProtocolRiftArenaCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AProtocolRiftArenaCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AProtocolRiftArenaCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AProtocolRiftArenaCharacter::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void AProtocolRiftArenaCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void AProtocolRiftArenaCharacter::DoSprintStart()
{
	bWantsToSprint = true;
	RefreshSprintState();
}

void AProtocolRiftArenaCharacter::DoSprintEnd()
{
	bWantsToSprint = false;
	RefreshSprintState();
}

void AProtocolRiftArenaCharacter::SetSprinting(bool bNewSprinting)
{
	if (bIsSprinting == bNewSprinting)
	{
		return;
	}

	bIsSprinting = bNewSprinting;
	UpdateMovementSpeed();
}

bool AProtocolRiftArenaCharacter::HasMovementInput() const
{
	return !LastMovementInput.IsNearlyZero();
}

bool AProtocolRiftArenaCharacter::CanSprint() const
{
	if (!HasMovementInput())
	{
		return false;
	}
	if (bIsCrouched)
	{
		return false;
	}
	const UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if(!MovementComponent)
	{
		return false;
	}

	if(MovementComponent->IsFalling())
	{
		return false;
	}

	return true;
}

void AProtocolRiftArenaCharacter::RefreshSprintState()
{
	const bool bShouldSprint = bWantsToSprint && CanSprint();
	SetSprinting(bShouldSprint);
}

void AProtocolRiftArenaCharacter::StopMove()
{
	LastMovementInput = FVector2D::ZeroVector;
	RefreshSprintState();
}

void AProtocolRiftArenaCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);
	RefreshSprintState();
}

void AProtocolRiftArenaCharacter::UpdateMovementSpeed()
{
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if(!MovementComponent)
	{
		return;
	}

	if (bIsCrouched)
	{
		MovementComponent->MaxWalkSpeed = CrouchSpeed;
		return;
	}

	if(bIsSprinting)
	{
		MovementComponent->MaxWalkSpeed = SprintSpeed;
		return;
	}

	MovementComponent->MaxWalkSpeed = WalkSpeed;

}

void AProtocolRiftArenaCharacter::DoCrouchStart()
{
	UE_LOG(LogProtocolRiftArena, Warning, TEXT("DoCrouchStart called"));
	Crouch();
}

void AProtocolRiftArenaCharacter::DoCrouchEnd()
{
	UE_LOG(LogProtocolRiftArena, Warning, TEXT("DoCrouchEnd called"));
	UnCrouch();
}

void AProtocolRiftArenaCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
	SetSprinting(false);
	UpdateMovementSpeed();


}

void AProtocolRiftArenaCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	Super::OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
	RefreshSprintState();
	UpdateMovementSpeed();
}

void AProtocolRiftArenaCharacter::UpdateCameraRoot(float DeltaTime)
{
	if (!CameraRoot)
	{
		return;
	}
	
	const FVector DesiredOffset = bIsCrouched ? CrouchingCameraRootOffset : StandingCameraRootOffset;
	const FVector TargetLocation = GetActorLocation() + DesiredOffset;

	const FVector NewLocation = FMath::VInterpTo(CameraRoot->GetComponentLocation(), TargetLocation, DeltaTime, CameraRootInterpSpeed);
	CameraRoot->SetWorldLocation(NewLocation);

}

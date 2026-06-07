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
#include "PRAWeaponBase.h"
#include "Net/UnrealNetwork.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "PRAAttributeSet.h"
#include "PRAGameplayTags.h"
#include "AbilitySystemComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

// ============================================================================
//							Constructor / Lifecycle
// ============================================================================

AProtocolRiftArenaCharacter::AProtocolRiftArenaCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UPRAAttributeSet>(TEXT("AttributeSet"));

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

void AProtocolRiftArenaCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		InitializeAttributes();
		AbilitySystemComponent->RegisterGameplayTagEvent(PRAGameplayTags::State_Death(), EGameplayTagEventType::NewOrRemoved).AddUObject(this, &AProtocolRiftArenaCharacter::OnDeathTagChanged);
	}

	if (CameraRoot)
	{
		CameraRoot->SetUsingAbsoluteLocation(true);
		CameraRoot->SetWorldLocation(GetActorLocation() + StandingCameraRootOffset);
	}

	if (HasAuthority())
	{
		SpawnDefaultWeapon();
	}

	if (AttributeSet)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("AttributeSet Init | Character: %s | Health: %.1f | MaxHealth: %.1f | Authority: %d"),
			*GetNameSafe(this),
			AttributeSet->GetHealth(),
			AttributeSet->GetMaxHealth(),
			HasAuthority());
	}
}

void AProtocolRiftArenaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateCameraRoot(DeltaTime);
	UpdateAimOffset(DeltaTime);
	UpdateAimRotation(DeltaTime);
}

// ============================================================================
//								Input Binding
// ============================================================================

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

		//Aim
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Started, this, &AProtocolRiftArenaCharacter::DoAimStart);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AProtocolRiftArenaCharacter::DoAimEnd);

		//Fire
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AProtocolRiftArenaCharacter::DoFireStart);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AProtocolRiftArenaCharacter::DoFireEnd);
	}
	else
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

// ============================================================================
//								GAS / Attributes
// ============================================================================

UAbilitySystemComponent* AProtocolRiftArenaCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AProtocolRiftArenaCharacter::InitializeAttributes()
{
	
	if(!HasAuthority())
	{
		return;
	}

	if (!AbilitySystemComponent)
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("AbilitySystemComponent is null on %s. Cannot InitializeAttributes."), *GetNameSafe(this));
		return;
	}

	if(!DefaultAttributeEffect)
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("DefaultAttributeEffect is null on %s. Cannot InitializeAttributes."), *GetNameSafe(this));
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

	if(!SpecHandle.IsValid())
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("Failed to create gameplay effect spec on %s. Cannot InitializeAttributes."), *GetNameSafe(this));
		return;
	}

	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

// ============================================================================
//								Input Actions
// ============================================================================

void AProtocolRiftArenaCharacter::Move(const FInputActionValue& Value)
{
	if(IsDead())
	{
		return;
	}
	// input is a Vector2D
	LastMovementInput = Value.Get<FVector2D>();
	
	//Sprint depends on whether the character is currently receiving movement input
	RefreshSprintState();

	// route the input
	DoMove(LastMovementInput.X, LastMovementInput.Y);
}

void AProtocolRiftArenaCharacter::Look(const FInputActionValue& Value)
{
	if(IsDead())
	{
		return;
	}
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

// ============================================================================
//							Locomotion / Sprint
// ============================================================================

void AProtocolRiftArenaCharacter::DoSprintStart()
{
	if(IsDead())
	{
		return;
	}
	bWantsToSprint = true;
	RefreshSprintState();
	if(!HasAuthority())
	{
		ServerSetWantsToSprint(true);
	}	
}

void AProtocolRiftArenaCharacter::DoSprintEnd()
{
	bWantsToSprint = false;
	RefreshSprintState();
	if (!HasAuthority())
	{
		ServerSetWantsToSprint(false);
	}
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
	if (bIsCrouched)
	{
		return false;
	}
	if (bIsAiming)
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
	if (bIsAiming)
	{
		MovementComponent->MaxWalkSpeed = AimWalkSpeed;
		return;
	}
	if(bIsSprinting)
	{
		MovementComponent->MaxWalkSpeed = SprintSpeed;
		return;
	}

	MovementComponent->MaxWalkSpeed = WalkSpeed;

}

// ============================================================================
//									Crouch
// ============================================================================

void AProtocolRiftArenaCharacter::DoCrouchStart()
{
	if(IsDead())
	{
		return;
	}
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


// ============================================================================
//									Camera
// ============================================================================

void AProtocolRiftArenaCharacter::UpdateCameraRoot(float DeltaTime)
{
	if (!CameraRoot)
	{
		return;
	}
	
	const FVector DesiredOffset = GetDesiredCameraRootOffset();

	const FRotator ControlRotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0.0f, ControlRotation.Yaw, 0.0f);

	const FVector RotatedOffset = YawRotation.RotateVector(DesiredOffset);
	const FVector TargetLocation = GetActorLocation() + RotatedOffset;

	const FVector NewLocation = FMath::VInterpTo(CameraRoot->GetComponentLocation(), TargetLocation, DeltaTime, CameraRootInterpSpeed);

	CameraRoot->SetWorldLocation(NewLocation);

}

// ============================================================================
//									Aiming
// ============================================================================

void AProtocolRiftArenaCharacter::DoAimStart()
{
	if(IsDead())
	{
		return;
	}
	bWantsToAim = true;
	SetSprinting(false);
	RefreshAimState();
	if(!HasAuthority())
	{
		ServerSetWantsToAim(true);
	}
}

void AProtocolRiftArenaCharacter::DoAimEnd()
{
	bWantsToAim = false;
	RefreshAimState();
	RefreshSprintState();
	if(!HasAuthority())
	{
		ServerSetWantsToAim(false);
	}
}

bool AProtocolRiftArenaCharacter::CanAim() const
{
	if (bIsSprinting)
	{
		return false;
	}
	const UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (!MovementComponent)
	{
		return false;
	}
	if (MovementComponent->IsFalling())
	{
		return false;
	}
	return true;
}

void AProtocolRiftArenaCharacter::RefreshAimState()
{
	const bool bShouldAim = bWantsToAim && CanAim();
	SetAiming(bShouldAim);
}

void AProtocolRiftArenaCharacter::SetAiming(bool bNewAiming)
{
	if (bIsAiming == bNewAiming)
	{
		return;
	}
	bIsAiming = bNewAiming;
	if (bIsAiming)
	{
		SetSprinting(false);
	}
	UpdateMovementSpeed();
}

FVector AProtocolRiftArenaCharacter::GetDesiredCameraRootOffset() const
{
	if(bIsAiming && bIsCrouched)
	{
		return CrouchAimCameraRootOffset;
	}
	if (bIsAiming)
	{
		return AimingCameraRootOffset;
	}
	if (bIsCrouched)
	{
		return CrouchingCameraRootOffset;
	}
	return StandingCameraRootOffset;
}


void AProtocolRiftArenaCharacter::UpdateAimOffset(float DeltaTime)
{
	if (!IsLocallyControlled() && !HasAuthority())
	{
		return;
	}

	const FRotator ControlRotation = GetControlRotation();

	float NormalizedPitch = ControlRotation.Pitch;

	if (NormalizedPitch > 180.0f)
	{
		NormalizedPitch -= 360.0f;
	}

	AimPitch = FMath::Clamp(NormalizedPitch, -90.0f, 90.0f);
}

void AProtocolRiftArenaCharacter::UpdateAimRotation(float DeltaTime)
{
	if (!bIsAiming)
	{
		return;
	}

	if (!GetController())
	{
		return;
	}

	const FRotator ControlRotation = GetControlRotation();
	const FRotator TargetRotation(0.0f, ControlRotation.Yaw, 0.0f);

	SetActorRotation(TargetRotation);
}

// ============================================================================
//								Combat / Weapon
// ============================================================================

void AProtocolRiftArenaCharacter::SpawnDefaultWeapon()
{
	if (!DefaultWeaponClass)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("DefaultWeaponClass is not set on %s. Please set it to a Blueprint subclass of PRAWeaponBase."), *GetNameSafe(this));
		return;
	}

	UWorld* World = GetWorld();
	if(!World)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Failed to get world on %s."), *GetNameSafe(this));
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	APRAWeaponBase* SpawnedWeapon = World->SpawnActor<APRAWeaponBase>(DefaultWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (!SpawnedWeapon)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Failed to spawn default weapon for %s. Please ensure DefaultWeaponClass is set to a valid Blueprint subclass of PRAWeaponBase."), *GetNameSafe(this));
		return;
	}

	EquipWeapon(SpawnedWeapon);
}

void AProtocolRiftArenaCharacter::EquipWeapon(APRAWeaponBase* NewWeapon)
{
	if (!NewWeapon)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Attempted to equip a null weapon on %s."), *GetNameSafe(this));
		return;
	}
	
	CurrentWeapon = NewWeapon;

	AttachCurrentWeaponToMesh();
}

void AProtocolRiftArenaCharacter::DoFireStart()
{
	if (IsDead())
	{
		return;
	}
	if(!CurrentWeapon)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Attempted to fire weapon while no weapon is equipped on %s."), *GetNameSafe(this));
		return;
	}
	CurrentWeapon->StartFire();
}

void AProtocolRiftArenaCharacter::DoFireEnd()
{
	if(!CurrentWeapon)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Attempted to stop firing weapon while no weapon is equipped on %s."), *GetNameSafe(this));
		return;
	}
	CurrentWeapon->StopFire();
}

void AProtocolRiftArenaCharacter::AttachCurrentWeaponToMesh()
{
	if (!CurrentWeapon)
	{
		return;
	}

	USkeletalMeshComponent* CharacterMesh = GetMesh();
	if(!CharacterMesh)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Failed to get Mesh component on %s while trying to equip weapon."), *GetNameSafe(this));
		return;
	}

	UE_LOG(LogProtocolRiftArena, Warning, TEXT("Attaching weapon | Character: %s | Weapon: %s | Socket: %s | Authority: %d | LocallyControlled: %d"),
		*GetNameSafe(this),
		*GetNameSafe(CurrentWeapon),
		*WeaponAttachSocketName.ToString(),
		HasAuthority(),
		IsLocallyControlled());	

	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponAttachSocketName);
}

// ============================================================================
//							Death / Dead State
// ============================================================================

bool AProtocolRiftArenaCharacter::IsDead() const
{
	const UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	return ASC && ASC->HasMatchingGameplayTag(PRAGameplayTags::State_Death());
}

void AProtocolRiftArenaCharacter::HandleDeath()
{
	if(!HasAuthority())
	{
		return;
	}
	
	if (IsDead())
	{
		return;
	}
	
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();

	if(!ASC || !DeathEffect)
	{
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Cannot apply death effect on %s. ASC or DeathEffect is null."), *GetNameSafe(this));
		return;
	}

	FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(DeathEffect, 1, EffectContext);
	if(SpecHandle.IsValid())
	{
		ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void AProtocolRiftArenaCharacter::OnDeathTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if (NewCount > 0)
	{
		ApplyDeathEffects();
	}
}

void AProtocolRiftArenaCharacter::ApplyDeathEffects()
{
	if(bDeathStateApplied)
	{
		return;
	}

	bDeathStateApplied = true;

	DoFireEnd();
	SetAiming(false);
	SetSprinting(false);

	GetCharacterMovement()->StopMovementImmediately();
	GetCharacterMovement()->DisableMovement();

	if(IsLocallyControlled())
	{
		if(APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			PC->SetIgnoreMoveInput(true);
			PC->SetIgnoreLookInput(true);

			if(DeathScreenWidgetClass && !DeathScreenWidget)
			{
				DeathScreenWidget = CreateWidget<UUserWidget>(PC, DeathScreenWidgetClass);
				if(DeathScreenWidget)
				{
					DeathScreenWidget->AddToViewport();
					UE_LOG(LogProtocolRiftArena, Warning, TEXT("Death UI check | Local: %d | PC: %s | WidgetClass: %s | ExistingWidget: %s"),
						IsLocallyControlled(),
						*GetNameSafe(GetController()),
						*GetNameSafe(DeathScreenWidgetClass),
						*GetNameSafe(DeathScreenWidget));
				}
			}
		}

		//Widget execution for local player death could go here, such as showing a respawn timer, or a "You Died" message. For this template, we will just log it.
		UE_LOG(LogProtocolRiftArena, Warning, TEXT("Player %s has died."), *GetNameSafe(this));
	}

	if (HasAuthority())
	{
		if (CurrentWeapon)
		{
			CurrentWeapon->SetLifeSpan(0.7f);
		}
		SetLifeSpan(0.7f);

	}
}

// ============================================================================
//								Replication
// ============================================================================

void AProtocolRiftArenaCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProtocolRiftArenaCharacter, CurrentWeapon);
	DOREPLIFETIME(AProtocolRiftArenaCharacter, bIsAiming);
	DOREPLIFETIME(AProtocolRiftArenaCharacter, bIsSprinting);
	DOREPLIFETIME(AProtocolRiftArenaCharacter, AimPitch);
}

void AProtocolRiftArenaCharacter::OnRep_CurrentWeapon()
{
	UE_LOG(LogProtocolRiftArena, Warning, TEXT("OnRep_CurrentWeapon | Character: %s | CurrentWeapon: %s | Authority: %d | LocallyControlled: %d"),
		*GetNameSafe(this),
		*GetNameSafe(CurrentWeapon),
		HasAuthority(),
		IsLocallyControlled());
	AttachCurrentWeaponToMesh();
}

void AProtocolRiftArenaCharacter::ServerSetWantsToAim_Implementation(bool bNewWantsToAim)
{
	bWantsToAim = bNewWantsToAim;
	if(bWantsToAim)
	{
		SetSprinting(false);
	}

	RefreshAimState();

	if (!bWantsToAim)
	{
		RefreshSprintState();
	}
}

void AProtocolRiftArenaCharacter::OnRep_IsAiming()
{
	UpdateMovementSpeed();
}

void AProtocolRiftArenaCharacter::ServerSetWantsToSprint_Implementation(bool bNewWantsToSprint)
{
	bWantsToSprint = bNewWantsToSprint;
	RefreshSprintState();
}

void AProtocolRiftArenaCharacter::OnRep_IsSprinting()
{
	UpdateMovementSpeed();
}
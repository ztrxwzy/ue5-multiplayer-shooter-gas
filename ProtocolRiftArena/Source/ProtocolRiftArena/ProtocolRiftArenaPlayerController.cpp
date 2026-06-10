// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProtocolRiftArenaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "ProtocolRiftArena.h"
#include "Widgets/Input/SVirtualJoystick.h"

void AProtocolRiftArenaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!IsLocalController())
	{
		return;
	}
	// only spawn touch controls on local player controllers
	if (ShouldUseTouchControls())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogProtocolRiftArena, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}

	if (!HUDWidgetClass)
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("No HUD widget class set on player controller."));
	}

	HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
	if(!HUDWidget)
	{
		UE_LOG(LogProtocolRiftArena, Error, TEXT("Could not spawn HUD widget."));
	}

	HUDWidget->AddToViewport();
}

void AProtocolRiftArenaPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!ShouldUseTouchControls())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

bool AProtocolRiftArenaPlayerController::ShouldUseTouchControls() const
{
	// are we on a mobile platform? Should we force touch?
	return SVirtualJoystick::ShouldDisplayTouchInterface() || bForceTouchControls;
}

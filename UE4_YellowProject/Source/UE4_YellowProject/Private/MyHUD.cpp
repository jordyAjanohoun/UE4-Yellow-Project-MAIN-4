// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"

AMyHUD::AMyHUD() {

}

bool AMyHUD::ShowSpecificMenu(class TSubclassOf<class UUserWidget> ClassToShow, bool GameOnly, bool ShowMouse, const FString & MessageToDisplay) {
	//Remove all widget first
	HideAllMenus();

	if (ClassToShow) {
		//Create the widget then add to screen
		UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), ClassToShow);
		CreatedWidget->AddToPlayerScreen();

		if (GameOnly) {
			// Set our input mode to game only which allows us full controll of the player
			GetOwningPlayerController()->SetInputMode(FInputModeGameOnly());
		}
		else {
			// Set our input mode to UI only, just in case we really don't want the player to be able to move
			FInputModeUIOnly InputMode;

			// This allows us to take the mouse out of the viewport
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			// Confirm our input mode
			GetOwningPlayerController()->SetInputMode(InputMode);
		}

		// If it is the end game party menu we have to show, display the message with
		UEndGamePartyMenu * EndGamePartyMenu = Cast<UEndGamePartyMenu>(CreatedWidget);
		if (EndGamePartyMenu) {
			// Set the message to display
			EndGamePartyMenu->MessageToDisplay = FText::FromString(MessageToDisplay);
		}

		// Update mouse cursor
			GetOwningPlayerController()->bShowMouseCursor = ShowMouse;

			return true;
	}

	// Meaning the inputed class to show was invalid
	return false;
}

void AMyHUD::HideAllMenus() {
	// Call an already established function to remove all widgets from the player's screen
	UWidgetLayoutLibrary::RemoveAllWidgets(this);
}
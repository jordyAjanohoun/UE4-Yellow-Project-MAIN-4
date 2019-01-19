// Fill out your copyright notice in the Description page of Project Settings.

#include "PauseMenu.h"

bool UPauseMenu::Initialize() {
	// Check if we fail the parent version of super first
	if (!Super::Initialize()) {
		return false;
	}

	// Bind the OnResumeClicked function to the ResumeButton delegate for OnClicked
	if (ResumeButton) {
		ResumeButton->OnClicked.AddDynamic(this, &UPauseMenu::OnResumeClicked);
	}

	// Bind the OnQuitGameClicked function to the QuitGameButton delegate for OnClicked
	if (QuitGameButton) {
		QuitGameButton->OnClicked.AddDynamic(this, &UPauseMenu::OnQuitGameClicked);
	}

	// Finishing the function 
	return true;
}
void UPauseMenu::OnResumeClicked() {
	// Check for a valid player reference
	AUE4_YellowProjectCharacter * Player = Cast<AUE4_YellowProjectCharacter>(GetOwningPlayerPawn());
	if (Player) {
		// if its valid then unpause the game, which handles removing the menu
		Player->UnPauseGame();
	}
}

void UPauseMenu::OnQuitGameClicked() {
	// Tell our owning player controller to quit the game
	if (GetOwningPlayer()) {
		GetOwningPlayer()->ConsoleCommand("quit");
	}
}

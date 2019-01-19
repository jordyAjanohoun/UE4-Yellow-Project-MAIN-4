// Fill out your copyright notice in the Description page of Project Settings.

#include "EndGamePartyMenu.h"

bool UEndGamePartyMenu::Initialize() {
	// Check if we fail the parent version of super first
	if (!Super::Initialize()) {
		return false;
	}

	// Bind the OnReplayClicked function to the ReplayButton delegate for OnClicked
	if (ReplayButton) {
		ReplayButton->OnClicked.AddDynamic(this, &UEndGamePartyMenu::OnReplayClicked);
	}

	// Bind the OnQuitGameClicked function to the QuitGameButton delegate for OnClicked
	if (QuitGameButton) {
		QuitGameButton->OnClicked.AddDynamic(this, &UEndGamePartyMenu::OnQuitGameClicked);
	}

	// Finishing the function 
	return true;
}
void UEndGamePartyMenu::OnReplayClicked() {
	// Reload/re-open/restart this level for a new try
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UEndGamePartyMenu::OnQuitGameClicked() {
	// Tell our owning player controller to quit the game
	if (GetOwningPlayer()) {
		GetOwningPlayer()->ConsoleCommand("quit");
	}
}
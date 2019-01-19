// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "UE4_YellowProjectCharacter.h"
#include "EndGamePartyMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API UEndGamePartyMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	/* Occurs on compile from the blueprint editor */
	virtual bool Initialize() override;

	/* Widget subclass of type Button that we are looking for named ReplayButton */
	UPROPERTY(meta = (BindWidget))
		class UButton* ReplayButton;

	// This will occur when the ReplayButton is clicked
	UFUNCTION()
		void OnReplayClicked();

	// Widget subclass of type Button that we are looking for named QuitGameButton
	UPROPERTY(meta = (BindWidget))
		class UButton* QuitGameButton;

	// This will occur when the QuitGameButton is clicked
	UFUNCTION()
		void OnQuitGameClicked();

public:
	// Message to display in the dead menu according to the way of dying 
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FText MessageToDisplay;
};

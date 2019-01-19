// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "UE4_YellowProjectCharacter.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	/* Occurs on compile from the blueprint editor */
	virtual bool Initialize() override;

private:
	/* Widget subclass of type Button that we are looking for named ResumeButton */
	UPROPERTY(meta = (BindWidget))
		class UButton* ResumeButton;

	// This will occur when the ResumeButton is clicked
	UFUNCTION()
		void OnResumeClicked();

	// Widget subclass of type Button that we are looking for named QuitGameButton
	UPROPERTY(meta = (BindWidget))
		class UButton* QuitGameButton;

	// This will occur when the QuitGameButton is clicked
	UFUNCTION()
		void OnQuitGameClicked();
	
};

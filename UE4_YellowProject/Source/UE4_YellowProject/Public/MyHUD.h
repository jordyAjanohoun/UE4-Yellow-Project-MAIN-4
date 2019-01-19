// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"
#include "EndGamePartyMenu.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();

	class TSubclassOf<UUserWidget> GetGameplayHUDClass() const { return GameplayHUDClass; }
	class TSubclassOf<UUserWidget> GetEndGamePartyMenuClass() const { return EndGamePartyMenuClass; }
	class TSubclassOf<UUserWidget> GetPauseMenuClass() const { return PauseMenuClass; }

	// Returns if or not we succeed to show the specific menu 
	bool ShowSpecificMenu(class TSubclassOf<class UUserWidget> ClassToShow, bool GameOnly, bool ShowMouse, const FString & MessageToDisplay = FString());

	// Hides all other menu's on screen
	UFUNCTION(BlueprintCallable, Category = "My HUD")
		void HideAllMenus();

protected:
	// The player's hud during gameplay, showing timer
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "My HUD")
		class TSubclassOf<UUserWidget> GameplayHUDClass {nullptr};

	// The menu to use when the player lose or win  
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "My HUD")
		class TSubclassOf<UUserWidget> EndGamePartyMenuClass { nullptr };

	// The menu to use when the player pause the game  
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "My HUD")
		class TSubclassOf<UUserWidget> PauseMenuClass { nullptr };
};

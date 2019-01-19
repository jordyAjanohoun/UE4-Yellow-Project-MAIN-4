// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UE4_YellowProjectCharacter.h"
#include "GameSupervisor.h"
#include "GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Widget_Gameplay.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API UWidget_Gameplay : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Supervisor")
		AGameSupervisor * GameSupervisor_p {};

	UFUNCTION(BlueprintPure, Category = "Widget|Gameplay")
		FText GetRemainingTime();
};

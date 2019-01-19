// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget_Gameplay.h"

FText UWidget_Gameplay::GetRemainingTime() {
	if (GameSupervisor_p) {
		FString FStringRemainingTime;
		GameSupervisor_p->GetFStringRemainingTime(FStringRemainingTime);
		return FText::FromString(FStringRemainingTime);
	}

	// if gamesupervisor_p is not set, error report with the value -2 
	return FText::AsNumber(-2);
}


// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UE4_YellowProjectGameMode.h"
#include "UE4_YellowProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4_YellowProjectGameMode::AUE4_YellowProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

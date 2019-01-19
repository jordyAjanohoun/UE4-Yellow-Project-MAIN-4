// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSupervisor.h"

// Sets default values
AGameSupervisor::AGameSupervisor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameSupervisor::BeginPlay()
{
	Super::BeginPlay();

	// Set the timer (time the player has to escape)
	GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &AGameSupervisor::TriggerEndOfParty, GameDurationInSeconds, false);

	// Precise function called on overlap begin event
	if (TriggerVolume_p) {
		TriggerVolume_p->OnActorBeginOverlap.AddDynamic(this, &AGameSupervisor::OnOverlapBegin);
	}
}

// Called every frame
void AGameSupervisor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameSupervisor::TriggerEndOfParty() {
	// Check for a valid player reference
	AUE4_YellowProjectCharacter * Player = Cast<AUE4_YellowProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator());
	if (Player) {
		// if its valid then stop the game, the player lose ! Pause the game and Show the end game party menu
		FString MessageToDisplay = FString::Printf(TEXT("You lose ! Time elapsed..."));
		Player->EndGameParty(MessageToDisplay);
	}
}

void AGameSupervisor::GetFStringRemainingTime(FString & FStringRemainingTime) {
	// Get and return the remaining time the player has to escape in FString format
	float RemainingTimeInSeconds = GetWorld()->GetTimerManager().GetTimerRemaining(TimerHandler);
	int RemainingTimeInMinutes = RemainingTimeInSeconds / 60;
	if (RemainingTimeInMinutes < 1) {
		FStringRemainingTime = FString::Printf(TEXT("RUN ! %d.%.2f"), RemainingTimeInMinutes, RemainingTimeInSeconds - RemainingTimeInMinutes * 60);
	}
	else if (RemainingTimeInMinutes < 3) {
		FStringRemainingTime = FString::Printf(TEXT("Run ! %d.%.2f"), RemainingTimeInMinutes, RemainingTimeInSeconds - RemainingTimeInMinutes * 60);
	}
	else {
		FStringRemainingTime = FString::Printf(TEXT("Run ! %d.%.2f"), RemainingTimeInMinutes, RemainingTimeInSeconds - RemainingTimeInMinutes * 60);
	}
}


void AGameSupervisor::OnOverlapBegin(AActor* FirstActor, AActor* OtherActor) {
	// if it is the player who is overlapping
	if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator()) {
		// Check for a valid player reference
		AUE4_YellowProjectCharacter * Player = Cast<AUE4_YellowProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator());
		if (Player) {
			// if its valid then stop the game, the player lose ! Pause the game and Show the enf game party menu
			float TimeElapsedInSeconds = GetWorld()->GetTimerManager().GetTimerElapsed(TimerHandler);
			int TimeElapsedInMinutes = TimeElapsedInSeconds / 60;
			FString MessageToDisplay = FString::Printf(TEXT("You win !! Score : %d.%.2f"),TimeElapsedInMinutes, TimeElapsedInSeconds - TimeElapsedInMinutes*60);
			Player->EndGameParty(MessageToDisplay);
		}
	}
}

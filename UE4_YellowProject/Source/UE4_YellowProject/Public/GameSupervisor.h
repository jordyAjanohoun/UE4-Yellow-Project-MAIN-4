// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE4_YellowProjectCharacter.h"
#include "Engine/TriggerVolume.h"
#include "GameSupervisor.generated.h"

UCLASS()
class UE4_YELLOWPROJECT_API AGameSupervisor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameSupervisor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Time the player has to escape !
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Duration")
		float GameDurationInSeconds{ 300 };

	// Timer handler needed by the World's TimerManager to set our timer 
	FTimerHandle TimerHandler;

	// Called when the coutdown timer reaches end to end the game because the time is ellapsed
	UFUNCTION()
		void TriggerEndOfParty();

	// The trigger volume near escape yellow door to reach without dying to win the game 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finish Game Area")
		ATriggerVolume* TriggerVolume_p{ nullptr };

public:
	// / Get the remaining time the player has to escape in FString format
	UFUNCTION()
		void GetFStringRemainingTime(FString & FStringRemainingTime);

	// Called when the player reaches escape yellow door to end the game (WIN)
	UFUNCTION()
	void OnOverlapBegin(AActor* FirstActor, AActor* OtherActor);
};

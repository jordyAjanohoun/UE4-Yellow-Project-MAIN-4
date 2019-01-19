// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap.h"
#include "Components/CapsuleComponent.h"
#include "PipeTrap.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API APipeTrap : public ATrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APipeTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Trigger volume Component - Capsule Shape 
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule|Shape")
		class UCapsuleComponent * TriggerCapsule_p{ nullptr };

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when an AActor Begins to overlap the trigger capsule volume of this AActor
	//virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};

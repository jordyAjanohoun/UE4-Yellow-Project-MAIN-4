// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "LaserTrap.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API ALaserTrap : public ATrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALaserTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Z location where the laser starts 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser|ZLocationStart")
		float ZLocationStart{50.0f};

	// Laser length (horizontal laser)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser|Length")
		float Length{600.0f};

	// Laser thickness
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser|Thickness")
		float Thickness{ 10.0f };

	// Trace Query Parameters for the ray cast (useful for the function LineTraceSingleByObjectType as parameter)
	static const FCollisionObjectQueryParams TraceQueryParameters;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

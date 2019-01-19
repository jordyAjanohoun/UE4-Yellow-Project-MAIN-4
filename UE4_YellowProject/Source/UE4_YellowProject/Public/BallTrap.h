// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "BallTrap.generated.h"

/**
 *
 */

UCLASS()
class UE4_YELLOWPROJECT_API ABallTrap : public ATrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABallTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Trigger volume Component - Sphere shape 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Trigger Sphere|Shape")
		class USphereComponent* TriggerSphere_p{ nullptr };

	// Trigger volume center Z location 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Sphere|Center Z Location")
		float CenterZLocation{ 50.0f };

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called when an AActor Begins to overlap the trigger sphere volume of this AActor
	//virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};

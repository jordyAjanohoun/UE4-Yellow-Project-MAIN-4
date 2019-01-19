// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Components/BoxComponent.h"
#include "StaticFireTrap.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YELLOWPROJECT_API AStaticFireTrap : public ATrap
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AStaticFireTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Center Fire Particle System Component pointer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|Center Fire PSC")
		class UParticleSystemComponent* CenterFirePSC_p{nullptr};

	// Second Fire Particle System Component pointer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|PSC 2")
		class UParticleSystemComponent* SecondFirePSC_p{ nullptr };

	// Second Fire Particle System Component location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|PSC 2 Location")
		FVector SecondFirePSCLocation = FVector(40.0f, 0.0f, 0.0f);

	// Third Fire Particle System Component pointer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|PSC 3")
		class UParticleSystemComponent* ThirdFirePSC_p{ nullptr };

	// Third Fire Particle System Component location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|PSC 3 Location")
		FVector ThirdFirePSCLocation = FVector(-45.0f, -50.0f, 0.0f);

	// Last Fire Particle System Component pointer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|PSC 4")
		class UParticleSystemComponent* LastFirePSC_p{ nullptr };

	// Last Fire Particle System Component location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Fire|PSC 4 Location")
		FVector LastFirePSCLocation = FVector(-45.0f, 50.0f, 0.0f);

	// Electric Particle System Component pointer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Electric|PSC")
		class UParticleSystemComponent* ElectricPSC_p{ nullptr };

	// Electric Particle System Component location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PSCs|Electric|Location")
		FVector ElectricPSCLocation = FVector(0.0f, 0.0f, 0.0f);

	// Trigger volume Component - Box shape 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Box|Shape")
		class UBoxComponent* TriggerBox_p{ nullptr };

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
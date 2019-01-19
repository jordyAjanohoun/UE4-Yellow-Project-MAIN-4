// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "UE4_YellowProjectCharacter.h"
#include "CharacterInteractableElement.generated.h"

UCLASS(abstract)
class UE4_YELLOWPROJECT_API ACharacterInteractableElement : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACharacterInteractableElement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Skin/shape of the character interactable element (this actor)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Static Mesh")
		UStaticMeshComponent * TheStaticMeshComponent_p {
		nullptr
	};

	// Horizontal direction : 1 (= Left To Right) or -1 (= Right to Left)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Direction|Horizontal")
		int HorizontalMovingDirection {
		1
	};

	// Vertical direction : -1 (= Top To Down) or 1 (= Down to Top)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Direction|Vertical")
		int VerticalMovingDirection {
		1
	};

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when an AActor Begins to overlap the trigger shape volume of this AActor
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};

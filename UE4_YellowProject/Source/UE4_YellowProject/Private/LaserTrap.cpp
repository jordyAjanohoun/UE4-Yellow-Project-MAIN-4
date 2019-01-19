// Fill out your copyright notice in the Description page of Project Settings.

#include "LaserTrap.h"

const FCollisionObjectQueryParams ALaserTrap::TraceQueryParameters(ECollisionChannel::ECC_Pawn);

// Sets default values
ALaserTrap::ALaserTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the Skin/shape of this character interactable element (this actor)

	auto ShapeCubeMeshAssetFromEditor = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	// If the object was found, set the Skin/shape
	if (ShapeCubeMeshAssetFromEditor.Object) {
		TheStaticMeshComponent_p->SetStaticMesh(ShapeCubeMeshAssetFromEditor.Object);
	}
}

// Called when the game starts or when spawned
void ALaserTrap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALaserTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Starting location to draw the laser
	FVector start = GetActorLocation() + FVector(0.0f, 0.0f, ZLocationStart);

	// Ending location of the drawing laser
	FVector end = start + FVector(0.0f,Length*HorizontalMovingDirection,0.0f);

	// Draw the laser
	DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 0.0f, 0.0f, Thickness);

	// Ray casting on the laser drew
	FHitResult Hit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), true, this);
	GetWorld()->LineTraceSingleByObjectType(Hit, start, end, TraceQueryParameters, TraceParameters);
	AActor * ActorHit = Hit.GetActor();
	// If the player character is overlapping this laser, end the game party
	if (ActorHit) {
		// Check for a valid player reference
		AUE4_YellowProjectCharacter * Player = Cast<AUE4_YellowProjectCharacter>(ActorHit);
		if (Player) {
			// if its valid then stop the game, the player lose ! Pause the game and Show the end game party menu
			FString MessageToDisplay = FString::Printf(TEXT("You lose ! You have overlapped a laser..."));
			Player->EndGameParty(MessageToDisplay);
		}
	}
}
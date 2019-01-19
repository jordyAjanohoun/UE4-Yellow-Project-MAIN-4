// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterInteractableElement.h"

// Sets default values
ACharacterInteractableElement::ACharacterInteractableElement()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheStaticMeshComponent_p = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
}

// Called when the game starts or when spawned
void ACharacterInteractableElement::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACharacterInteractableElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterInteractableElement::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	// if it is not this actor who is triggering its trigger shape
	if (OtherActor && (OtherActor != this) && OtherComp) {
		if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator()) {
			// Check for a valid player reference
			AUE4_YellowProjectCharacter * Player = Cast<AUE4_YellowProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator());
			if (Player) {
				// if its valid then stop the game, the player lose ! Pause the game and Show the end game party menu
				FString MessageToDisplay = FString::Printf(TEXT("You lose ! You have overlapped a trap..."));
				Player->EndGameParty(MessageToDisplay);
			}
		}
	}
}


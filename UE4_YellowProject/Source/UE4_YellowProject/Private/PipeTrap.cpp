// Fill out your copyright notice in the Description page of Project Settings.

#include "PipeTrap.h"

// Sets default values
APipeTrap::APipeTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the Skin/shape of this character interactable element (this actor)

	auto ShapePipeMeshAssetFromEditor = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	// If the object was found, set the Skin/shape
	if (ShapePipeMeshAssetFromEditor.Object) {
		TheStaticMeshComponent_p->SetStaticMesh(ShapePipeMeshAssetFromEditor.Object);
	}

	// Set the trigger capsule
	TriggerCapsule_p = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule_p->InitCapsuleSize(42.f, 96.0f);
	TriggerCapsule_p->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule_p->SetupAttachment(RootComponent);

	// Precise function called on overlap begin event
	TriggerCapsule_p->OnComponentBeginOverlap.AddDynamic(this, &APipeTrap::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APipeTrap::BeginPlay()
{
	Super::BeginPlay();

	TriggerCapsule_p->SetRelativeLocation(FVector(0.0f, 0.0f, 7.0f));

}

// Called every frame
void APipeTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*void APipeTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	// if it is not this actor who is triggering its trigger capsule
	if (OtherActor && (OtherActor != this) && OtherComp) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("PipeTrap is overlaped"));
		}
	}
}*/
// Fill out your copyright notice in the Description page of Project Settings.

#include "BallTrap.h"

// Sets default values
ABallTrap::ABallTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the Skin/shape of this character interactable element (this actor)

	auto ShapeSphereMeshAssetFromEditor = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	// If the object was found, set the Skin/shape
	if (ShapeSphereMeshAssetFromEditor.Object) {
		TheStaticMeshComponent_p->SetStaticMesh(ShapeSphereMeshAssetFromEditor.Object);
	}

	// Set the trigger sphere of this actor
	TriggerSphere_p = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	TriggerSphere_p->InitSphereRadius(51.0f);
	TriggerSphere_p->SetCollisionProfileName(TEXT("Trigger"));
	TriggerSphere_p->SetupAttachment(RootComponent);

	// Precise function called on overlap begin event
	TriggerSphere_p->OnComponentBeginOverlap.AddDynamic(this, &ABallTrap::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ABallTrap::BeginPlay()
{
	Super::BeginPlay();

	// Place the Trigger Sphere correctly (for embrace the mesh with)
	TriggerSphere_p->SetRelativeLocation(FVector(0.0f, 0.0f, CenterZLocation));
}

// Called every frame
void ABallTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*void ABallTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	// if it is not this actor who is triggering its trigger sphere
	if (OtherActor && (OtherActor != this) && OtherComp) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("BallTrap is overlaped"));
		}
	}
}*/


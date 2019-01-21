
#include "BallTrap.h"

// Sets default values
ABallTrap::ABallTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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



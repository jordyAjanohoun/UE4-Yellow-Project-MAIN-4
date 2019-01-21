// Fill out your copyright notice in the Description page of Project Settings.

#include "StaticFireTrap.h"

// Sets default values
AStaticFireTrap::AStaticFireTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set the Skin/shape of this character interactable element (this actor)
	auto MeshAssetFromEditor = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'"));
	// If the object (mesh) was found, set the Skin/shape
	if (MeshAssetFromEditor.Object) {
		TheStaticMeshComponent_p->SetStaticMesh(MeshAssetFromEditor.Object);
		TheStaticMeshComponent_p->SetRelativeScale3D(FVector(1.0f,1.0f,0.65f));
	}

	// Set PSCs

	// Get particule systems references from the editor
	auto FireParticuleSystemFromEditor = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	auto ElectricParticuleSystemFromEditor = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	auto SmokeParticuleSystemFromEditor = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
	// If the particule systems were found
	if (FireParticuleSystemFromEditor.Object && ElectricParticuleSystemFromEditor.Object && SmokeParticuleSystemFromEditor.Object) {
		// Create and init Particle System Components
		CenterFirePSC_p = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Center Fire PSC_p"));
		CenterFirePSC_p -> SetTemplate(FireParticuleSystemFromEditor.Object);
		CenterFirePSC_p -> SetupAttachment(RootComponent);
		CenterFirePSC_p -> bAutoActivate = true;

		SecondFirePSC_p = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Second Fire PSC_p"));
		SecondFirePSC_p->SetTemplate(FireParticuleSystemFromEditor.Object);
		SecondFirePSC_p->SetupAttachment(RootComponent);
		SecondFirePSC_p->bAutoActivate = true;

		ThirdFirePSC_p = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Third Fire PSC_p"));
		ThirdFirePSC_p->SetTemplate(FireParticuleSystemFromEditor.Object);
		ThirdFirePSC_p->SetupAttachment(RootComponent);
		ThirdFirePSC_p->bAutoActivate = true;

		LastFirePSC_p = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Last Fire PSC_p"));
		LastFirePSC_p->SetTemplate(FireParticuleSystemFromEditor.Object);
		LastFirePSC_p->SetupAttachment(RootComponent);
		LastFirePSC_p->bAutoActivate = true;

		ElectricPSC_p = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Electric PSC_p"));
		ElectricPSC_p->SetTemplate(ElectricParticuleSystemFromEditor.Object);
		ElectricPSC_p->SetupAttachment(RootComponent);
		ElectricPSC_p->bAutoActivate = true;
	}

	// Set the trigger box
	TriggerBox_p = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox_p->SetCollisionProfileName(TEXT("Trigger"));
	TriggerBox_p->SetupAttachment(RootComponent);
	TriggerBox_p->InitBoxExtent(FVector(60.0f,50.0f,85.0f));

	// Precise function called on overlap begin event
	TriggerBox_p->OnComponentBeginOverlap.AddDynamic(this, &AStaticFireTrap::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AStaticFireTrap::BeginPlay()
{
	Super::BeginPlay();

	// Place the Trigger box correctly (for meet the PSCs)
	TriggerBox_p->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	// Set PSCs location 
	CenterFirePSC_p -> SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	ElectricPSC_p -> SetRelativeLocation(ElectricPSCLocation);
	SecondFirePSC_p->SetRelativeLocation(SecondFirePSCLocation);
	ThirdFirePSC_p->SetRelativeLocation(ThirdFirePSCLocation);
	LastFirePSC_p->SetRelativeLocation(LastFirePSCLocation);
}

// Called every frame
void AStaticFireTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



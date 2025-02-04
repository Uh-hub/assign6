#include "RotateInCircle.h"

ARotateInCircle::ARotateInCircle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed;
}


void ARotateInCircle::BeginPlay()
{
	Super::BeginPlay();
	RotationSpeed = FMath::RandRange(20.0f, 40.0f);
}


void ARotateInCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}


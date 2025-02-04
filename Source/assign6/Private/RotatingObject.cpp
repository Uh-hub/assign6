#include "RotatingObject.h"

ARotatingObject::ARotatingObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 90.0f;
}


void ARotatingObject::BeginPlay()
{
	Super::BeginPlay();
	
	//¿¢ÅÍÀÇ À§Ä¡
	SetActorLocation(FVector(-12310.0f, -170.0f, 3570.0f));
}


void ARotatingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

}


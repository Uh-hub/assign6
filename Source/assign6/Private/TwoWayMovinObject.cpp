#include "TwoWayMovinObject.h"


ATwoWayMovinObject::ATwoWayMovinObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	PrimaryActorTick.bCanEverTick = true;

	//이동 속도
	MovingSpeed = 150.0f;
	//시작 지점
	StartingLocation = FVector(-60.0f, -150.0f, 410.0f);
	MaxRange = FVector(-1300.0f, -150.0f, 1000.0f);
}

void ATwoWayMovinObject::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(StartingLocation);
}


void ATwoWayMovinObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//추가



	FVector Location = GetActorLocation();
	if ((Location - StartingLocation).Size() > (MaxRange - StartingLocation).Size())
	{//현재 위치와 시작점까지의 거리가 원래 목표 거리보다 멀어졌다면 돌아가기
		FVector Temp = MaxRange;
		MaxRange = StartingLocation;
		StartingLocation = Temp;
	}

	FVector Direction = (MaxRange - Location).GetSafeNormal();
	Location += Direction * MovingSpeed * DeltaTime;
	SetActorLocation(Location);
}


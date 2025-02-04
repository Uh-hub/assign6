#include "FallingFloor.h"

AFallingFloor::AFallingFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotateSize = 90.0f;
	PrimaryActorTick.bCanEverTick = true;
	enabled = true;
	
}

void AFallingFloor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Rotate_Timer, this, &AFallingFloor::RotateFloor, FMath::RandRange(3.0f, 8.0f), true);
}

void AFallingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateActor();
}

//일정 시간마다 RotateFloor 함수가 스위치를 온 오프
void AFallingFloor::RotateFloor()
{
	enabled = !enabled;
}


//RotateActor는 enabled -> 발판O, !enabled -> 발판X(90도 회전)(일정 시간이 지날때마다 발판이 회전하여 사라짐)
void AFallingFloor::RotateActor()
{
	//enabled = true -> Rotate X = 0
	//enabled = flase -> Rotate X = 90
	if (enabled)
	{
		SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	else {
		SetActorRotation(FRotator(RotateSize, 0.0f, 0.0f));
	}
}


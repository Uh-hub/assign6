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

//���� �ð����� RotateFloor �Լ��� ����ġ�� �� ����
void AFallingFloor::RotateFloor()
{
	enabled = !enabled;
}


//RotateActor�� enabled -> ����O, !enabled -> ����X(90�� ȸ��)(���� �ð��� ���������� ������ ȸ���Ͽ� �����)
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


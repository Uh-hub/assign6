#include "TwoWayMovinObject.h"


ATwoWayMovinObject::ATwoWayMovinObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	PrimaryActorTick.bCanEverTick = true;

	//�̵� �ӵ�
	MovingSpeed = 150.0f;
	//���� ����
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
	//�߰�



	FVector Location = GetActorLocation();
	if ((Location - StartingLocation).Size() > (MaxRange - StartingLocation).Size())
	{//���� ��ġ�� ������������ �Ÿ��� ���� ��ǥ �Ÿ����� �־����ٸ� ���ư���
		FVector Temp = MaxRange;
		MaxRange = StartingLocation;
		StartingLocation = Temp;
	}

	FVector Direction = (MaxRange - Location).GetSafeNormal();
	Location += Direction * MovingSpeed * DeltaTime;
	SetActorLocation(Location);
}


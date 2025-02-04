#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TwoWayMovinObject.generated.h"

//�պ� ��ϴ� ����
UCLASS()
class ASSIGN6_API ATwoWayMovinObject : public AActor
{
	GENERATED_BODY()
	
public:	
	ATwoWayMovinObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Object|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Components")
	UStaticMeshComponent* StaticMeshComp;

	//�� �����Ӹ��� ������ �ӵ�(�������Ʈ������ ���� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	float MovingSpeed; 

	//�պ� ���� ����(�������Ʈ������ ���� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	FVector MaxRange;
	
	//�պ� ���� ����(�������Ʈ������ ���� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	FVector StartingLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

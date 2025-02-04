#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingObject.generated.h"

UCLASS()
class ASSIGN6_API ARotatingObject : public AActor
{
	//ȸ���ϴ� ��ü
	GENERATED_BODY()
	
public:	
	ARotatingObject();

protected:
	//Root component�� �� SceneRoot
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Object|Components")
	USceneComponent* SceneRoot; 

	//Mesh�� Static Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category="Object|Components")
	UStaticMeshComponent* StaticMeshComp; 

	//ȸ�� �ӵ�(�������Ʈ������ ���� �����ϵ��� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Object|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

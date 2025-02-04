#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingObject.generated.h"

UCLASS()
class ASSIGN6_API ARotatingObject : public AActor
{
	//회전하는 객체
	GENERATED_BODY()
	
public:	
	ARotatingObject();

protected:
	//Root component로 할 SceneRoot
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Object|Components")
	USceneComponent* SceneRoot; 

	//Mesh는 Static Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category="Object|Components")
	UStaticMeshComponent* StaticMeshComp; 

	//회전 속도(블루프린트에서도 수정 가능하도록 선언)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Object|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

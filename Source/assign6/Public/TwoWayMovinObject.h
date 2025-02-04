#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TwoWayMovinObject.generated.h"

//왕복 운동하는 엑터
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

	//매 프레임마다 움직일 속도(블루프린트에서도 수정 가능)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	float MovingSpeed; 

	//왕복 종료 지점(블루프린트에서도 수정 가능)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	FVector MaxRange;
	
	//왕복 시작 지점(블루프린트에서도 수정 가능)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	FVector StartingLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

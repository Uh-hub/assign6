#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateInCircle.generated.h"

UCLASS()
class ASSIGN6_API ARotateInCircle : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotateInCircle();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Object|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Object|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

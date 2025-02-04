#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RollObject.generated.h"

UCLASS()
class ASSIGN6_API ARollObject : public AActor
{
	GENERATED_BODY()
	
public:	

	ARollObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Object|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Object|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	float RotationSpeed;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

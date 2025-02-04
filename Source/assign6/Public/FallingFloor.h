#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingFloor.generated.h"

UCLASS()
class ASSIGN6_API AFallingFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	AFallingFloor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Object|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Object|Components")
	UStaticMeshComponent* StaticMeshComp;

	//FTimer
	FTimerHandle Rotate_Timer;

	//Rotate 
	UFUNCTION()
	void RotateActor();

	//Rotate ½ºÀ§Ä¡
	UFUNCTION()
	void RotateFloor();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Properties")
	float RotateSize;

	

	bool enabled;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};

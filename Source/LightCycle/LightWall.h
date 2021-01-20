// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "LightWall.generated.h"

UCLASS()
class LIGHTCYCLE_API ALightWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightWall();

	UFUNCTION(BlueprintCallable)
	void ExtendLightWall(FVector Location);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LightWallHeight = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bVisible = false;
	

private:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* PMesh;

	
	TArray<int32> IndicesTemplate {
		0,1,2,
        1,3,2,
        2,1,0,
        2,3,1
    };

	TArray<FVector> Vertices;
	TArray<int32> Indices;
	int32 WallSegmentCount = 0;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "LightWall.h"

// Sets default values
ALightWall::ALightWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	// Multi-Threaded PhysX cooking.
	PMesh->bUseAsyncCooking = true;

}

void ALightWall::ExtendLightWall(const FVector Location)
{
	// Skip this the first time (we need 4 vertices to generate one stripe).
	if(Vertices.Num() > 2)
	{
		WallSegmentCount += 2;
		for (int32 Index : IndicesTemplate)
			Indices.Add(WallSegmentCount + Index);
	}
	// Add given location and location with wall height to vertex list.
	Vertices.Add(Location);
	Vertices.Add(Location + FVector(0,0,LightWallHeight));
	
	// Clear section -> Remove all triangles.
	// Updating section does not allow the change of the topology.
	// Adding new sections costs way more speed (in the long run) than deleting and creating a new section.
	PMesh->CreateMeshSection_LinearColor(0, Vertices, Indices,
		TArray<FVector>(),
		TArray<FVector2D>(),
		TArray<FVector2D>(),
		TArray<FVector2D>(),
		TArray<FVector2D>(),
		TArray<FLinearColor>(),
		TArray<FProcMeshTangent>(),
		true);
	
	PMesh->SetMeshSectionVisible(0, bVisible);
}

// Called when the game starts or when spawned
void ALightWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


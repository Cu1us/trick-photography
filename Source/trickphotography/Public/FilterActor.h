// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FilterableInterface.h"
#include "FilterActor.generated.h"

UCLASS()
class TRICKPHOTOGRAPHY_API AFilterActor : public AActor, public IFilterableInterface
{
	GENERATED_BODY()
	
// public:	
// 	// Sets default values for this actor's properties
// 	AFilterActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<UActorComponent*> FilterableComponents;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	void OnAnyPhoto_Implementation() override;
	void OnAnyPhotoFinished_Implementation() override;
	void OnThermalPhoto_Implementation() override;
	void OnThermalPhotoFinished_Implementation() override;
	void OnUVPhoto_Implementation() override;
	void OnUVPhotoFinished_Implementation() override;
	void OnXrayPhoto_Implementation() override;
	void OnXrayPhotoFinished_Implementation() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FilterActor.h"
#include "PickupableInterface.h"
#include "Math/Transform.h"
#include "Pickup.generated.h"

/**
 *
 */
UCLASS()
class TRICKPHOTOGRAPHY_API APickup : public AFilterActor, public IPickupableInterface
{
	GENERATED_BODY()

//public:
	// Sets default values for this actor's properties
	//AFilterActor();

protected:
	TArray<UPrimitiveComponent*> PhysicsSimulatedComponents;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnPickup_Implementation() override;
	void OnDrop_Implementation() override;
	bool CanBePickedUp_Implementation() override;
	//void Activate_Implementation(FTransform cameraTransform) override;
};

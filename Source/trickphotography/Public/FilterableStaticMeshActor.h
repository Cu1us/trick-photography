// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "FilterableInterface.h"
#include "FilterableStaticMeshActor.generated.h"

/**
 *
 */
UENUM(Blueprintable, BlueprintType)
enum class FilterVisibility : uint8
{
	Visible UMETA(DisplayName = "Visible"),
	Hidden UMETA(DisplayName = "Hidden"),
	Unaffected UMETA(DisplayName = "Unaffected")
};


UCLASS()
class TRICKPHOTOGRAPHY_API AFilterableStaticMeshActor : public AStaticMeshActor, public IFilterableInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UMaterialInterface* DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Interaction")
	FilterVisibility ThermalInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Interaction")
	UMaterialInterface *ThermalMaterial;

	void OnThermalPhoto_Implementation() override;

	void OnPhotoFinished_Implementation() override;
};

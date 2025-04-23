// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "FilterableStaticMeshActor.generated.h"

/**
 *
 */
UCLASS()
class TRICKPHOTOGRAPHY_API AFilterableStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UMaterialInterface* DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Interaction")
	FilterVisibility ThermalInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Interaction")
	UMaterialInterface *ThermalMaterial;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnThermalPhoto();
	void OnThermalPhoto_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnPhotoFinished();
	void OnPhotoFinished_Implementation();
};

UENUM(BlueprintType)
enum class FilterVisibility : uint8
{
	Visible UMETA(DisplayName = "Visible"),
	Hidden UMETA(DisplayName = "Hidden"),
	Unaffected UMETA(DisplayName = "Unaffected")
};
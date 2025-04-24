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

	UMaterialInterface *DefaultMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|Thermal")
	FilterVisibility ThermalInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|Thermal")
	UMaterialInterface *ThermalMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|UV")
	FilterVisibility UVInteraction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|X-Ray")
	FilterVisibility XrayInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|X-Ray")
	UMaterialInterface *XrayMaterial;

	void OnAnyPhoto_Implementation() override;
	void OnAnyPhotoFinished_Implementation() override;
	void OnThermalPhoto_Implementation() override;
	void OnThermalPhotoFinished_Implementation() override;
	void OnUVPhoto_Implementation() override;
	void OnUVPhotoFinished_Implementation() override;
	void OnXrayPhoto_Implementation() override;
	void OnXrayPhotoFinished_Implementation() override;

private:
	bool HiddenDueToFilterSetting;
};

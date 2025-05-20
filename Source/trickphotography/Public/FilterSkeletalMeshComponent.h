// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "FilterableInterface.h"
#include "FilterableStaticMeshActor.h"
#include "FilterSkeletalMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Filterable), meta = (BlueprintSpawnableComponent))
class TRICKPHOTOGRAPHY_API UFilterSkeletalMeshComponent : public USkeletalMeshComponent, public IFilterableInterface
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|UV")
	UMaterialInterface *UVMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|X-Ray")
	FilterVisibility XrayInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|X-Ray")
	UMaterialInterface *XrayMaterial;

	UFUNCTION(BlueprintCallable, Category = "Filter Interaction")
	void SetMainMaterial(UMaterialInterface *NewMaterial);

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

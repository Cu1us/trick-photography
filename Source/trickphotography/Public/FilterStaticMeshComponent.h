// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "FilterableInterface.h"
#include "FilterableStaticMeshActor.h"
#include "FilterStaticMeshComponent.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Filterable), meta = (BlueprintSpawnableComponent))
class TRICKPHOTOGRAPHY_API UFilterStaticMeshComponent : public UStaticMeshComponent, public IFilterableInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UMaterialInterface *DefaultMaterial;
	ECollisionChannel DefaultCollisionType;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|Invisibility")
	bool IsInvisible;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials\|Invisibility")
	UMaterialInterface *InvisMaterial;

	UFUNCTION(BlueprintCallable, Category = "Filter Interaction")
	void SetMainMaterial(UMaterialInterface *NewMaterial);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Make Invisible", Keywords = "Invisibility", Category = "Filter Interaction"))
	void MakeInvisible();

	void OnAnyPhoto_Implementation() override;
	void OnAnyPhotoFinished_Implementation() override;
	void OnThermalPhoto_Implementation() override;
	void OnThermalPhotoFinished_Implementation() override;
	void OnUVPhoto_Implementation() override;
	void OnUVPhotoFinished_Implementation() override;
	void OnXrayPhoto_Implementation() override;
	void OnXrayPhotoFinished_Implementation() override;
	void OnInvisPhoto_Implementation() override;
	void OnInvisPhotoFinished_Implementation() override;
	void OnRevealFromInvisibility_Implementation() override;

private:
	bool HiddenDueToFilterSetting;
};

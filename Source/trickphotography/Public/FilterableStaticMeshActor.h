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

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Reveal From Invisibility", Keywords = "Invisibility", Category = "Filter Interaction"))
	void RevealFromInvisibility();
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

private:
	bool HiddenDueToFilterSetting;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "FilterableInterface.h"
#include "FilterableStaticMeshActor.h"
#include "FilterTextRenderComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Filterable), meta = (BlueprintSpawnableComponent))
class TRICKPHOTOGRAPHY_API UFilterTextRenderComponent : public UTextRenderComponent, public IFilterableInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleByPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleInThermal;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleInUV;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Filter Visibility")
	bool VisibleInXray;

	//void OnAnyPhoto_Implementation() override;
	void OnAnyPhotoFinished_Implementation() override;
	void OnThermalPhoto_Implementation() override;
	//void OnThermalPhotoFinished_Implementation() override;
	void OnUVPhoto_Implementation() override;
	//void OnUVPhotoFinished_Implementation() override;
	void OnXrayPhoto_Implementation() override;
	//void OnXrayPhotoFinished_Implementation() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FilterableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UFilterableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class TRICKPHOTOGRAPHY_API IFilterableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnAnyPhoto();
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnAnyPhotoFinished();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnThermalPhoto();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnThermalPhotoFinished();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnUVPhoto();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnUVPhotoFinished();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnXrayPhoto();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnXrayPhotoFinished();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnInvisPhoto();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnInvisPhotoFinished();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Filter Interaction")
	void OnRevealFromInvisibility();

public:
	FString GetInterfaceName();
};

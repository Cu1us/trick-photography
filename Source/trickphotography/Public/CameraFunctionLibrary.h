// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CameraFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TRICKPHOTOGRAPHY_API UCameraFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Convert Render Target to Texture", Keywords = "Texture", Category = "Custom functions"))
	static UTexture2D* ConvertRenderTargetToTexture(UTextureRenderTarget2D* InputRenderTarget);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Int Test Function", Category = "Custom functions"))
	static void IntTestFunction(const int Input);
};

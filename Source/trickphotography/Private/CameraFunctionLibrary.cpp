// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraFunctionLibrary.h"
#include "Engine/TextureRenderTarget2D.h"

UTexture2D* UCameraFunctionLibrary::ConvertRenderTargetToTexture(UTextureRenderTarget2D *InputRenderTarget)
{
    UTexture2D *Photo = UTexture2D::CreateTransient(
        InputRenderTarget->SizeX,
        InputRenderTarget->SizeY,
        InputRenderTarget->GetFormat(),
        "mynewtexturehihihaha");

    return InputRenderTarget->ConstructTexture2D(InputRenderTarget->GetOuter(), "CameraImage", EObjectFlags::RF_NoFlags, CTF_DeferCompression);
}


void UCameraFunctionLibrary::IntTestFunction(const int Input)
{
    
}
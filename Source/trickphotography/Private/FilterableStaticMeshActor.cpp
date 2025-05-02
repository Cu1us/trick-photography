// Fill out your copyright notice in the Description page of Project Settings.

#include "FilterableStaticMeshActor.h"

// AFilterableStaticMeshActor::AFilterableStaticMeshActor(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
// {
//     UE_LOG(LogTemp, Warning, TEXT("Thing created!!!!"))
// }

void AFilterableStaticMeshActor::BeginPlay()
{
    Super::BeginPlay();

    HiddenDueToFilterSetting = false;
    DefaultMaterial = GetStaticMeshComponent()->GetMaterial(0);
}

// Any
void AFilterableStaticMeshActor::OnAnyPhoto_Implementation()
{
}
void AFilterableStaticMeshActor::OnAnyPhotoFinished_Implementation()
{
}

// Thermal
void AFilterableStaticMeshActor::OnThermalPhoto_Implementation()
{
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, ThermalMaterial);
        break;
    case FilterVisibility::Hidden:
        if (GetStaticMeshComponent()->IsVisible())
        {
            GetStaticMeshComponent()->SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void AFilterableStaticMeshActor::OnThermalPhotoFinished_Implementation()
{
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            GetStaticMeshComponent()->SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}

// UV
void AFilterableStaticMeshActor::OnUVPhoto_Implementation()
{
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, UVMaterial);

        break;
    case FilterVisibility::Hidden:
        GetStaticMeshComponent()->SetVisibility(false);
        break;
    default:
        break;
    }
}
void AFilterableStaticMeshActor::OnUVPhotoFinished_Implementation()
{
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        GetStaticMeshComponent()->SetVisibility(true);
        break;
    default:
        break;
    }
}

// X-Ray
void AFilterableStaticMeshActor::OnXrayPhoto_Implementation()
{
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, XrayMaterial);
        break;
    case FilterVisibility::Hidden:
        if (GetStaticMeshComponent()->IsVisible())
        {
            GetStaticMeshComponent()->SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void AFilterableStaticMeshActor::OnXrayPhotoFinished_Implementation()
{
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            GetStaticMeshComponent()->SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}
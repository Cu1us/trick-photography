// Fill out your copyright notice in the Description page of Project Settings.


#include "FilterStaticMeshComponent.h"

void UFilterStaticMeshComponent::BeginPlay()
{
    Super::BeginPlay();

    HiddenDueToFilterSetting = false;

    DefaultMaterial = GetMaterial(0);
}

// Any
void UFilterStaticMeshComponent::OnAnyPhoto_Implementation()
{
}
void UFilterStaticMeshComponent::OnAnyPhotoFinished_Implementation()
{
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        if (HiddenDueToFilterSetting)
        {
            SetVisibility(true);
            HiddenDueToFilterSetting = false;
        }
        break;
    default:
        break;
    }
}

// Thermal
void UFilterStaticMeshComponent::OnThermalPhoto_Implementation()
{
    switch (ThermalInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, ThermalMaterial);
        break;
    case FilterVisibility::Hidden:
        if (IsVisible())
        {
            SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void UFilterStaticMeshComponent::OnThermalPhotoFinished_Implementation()
{
}

// UV
void UFilterStaticMeshComponent::OnUVPhoto_Implementation()
{
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        //SetVisibility(true);
        break;
    case FilterVisibility::Hidden:
        SetVisibility(false);
        break;
    default:
        break;
    }
}
void UFilterStaticMeshComponent::OnUVPhotoFinished_Implementation()
{
    switch (UVInteraction)
    {
        case FilterVisibility::Visible:
        //SetVisibility(false);
        break;
    case FilterVisibility::Hidden:
        SetVisibility(true);
        break;
    default:
        break;
    }
}

// X-Ray
void UFilterStaticMeshComponent::OnXrayPhoto_Implementation()
{
    switch (XrayInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, XrayMaterial);
        break;
    case FilterVisibility::Hidden:
        if (IsVisible())
        {
            SetVisibility(false);
            HiddenDueToFilterSetting = true;
        }
        break;
    default:
        break;
    }
}
void UFilterStaticMeshComponent::OnXrayPhotoFinished_Implementation()
{
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "FilterSkeletalMeshComponent.h"

void UFilterSkeletalMeshComponent::SetMainMaterial(UMaterialInterface *NewMaterial)
{
    DefaultMaterial = NewMaterial;
    SetMaterial(0, NewMaterial);
}
void UFilterSkeletalMeshComponent::BeginPlay()
{
    Super::BeginPlay();

    HiddenDueToFilterSetting = false;

    DefaultMaterial = GetMaterial(0);
}

// Any
void UFilterSkeletalMeshComponent::OnAnyPhoto_Implementation()
{
}
void UFilterSkeletalMeshComponent::OnAnyPhotoFinished_Implementation()
{
}

// Thermal
void UFilterSkeletalMeshComponent::OnThermalPhoto_Implementation()
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
void UFilterSkeletalMeshComponent::OnThermalPhotoFinished_Implementation()
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

// UV
void UFilterSkeletalMeshComponent::OnUVPhoto_Implementation()
{
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, UVMaterial);
        break;
    case FilterVisibility::Hidden:
        SetVisibility(false);
        break;
    default:
        break;
    }
}
void UFilterSkeletalMeshComponent::OnUVPhotoFinished_Implementation()
{
    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        SetMaterial(0, DefaultMaterial);
        break;
    case FilterVisibility::Hidden:
        SetVisibility(true);
        break;
    default:
        break;
    }
}

// X-Ray
void UFilterSkeletalMeshComponent::OnXrayPhoto_Implementation()
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
void UFilterSkeletalMeshComponent::OnXrayPhotoFinished_Implementation()
{
    switch (XrayInteraction)
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
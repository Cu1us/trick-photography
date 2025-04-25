// Fill out your copyright notice in the Description page of Project Settings.

#include "FilterableStaticMeshActor.h"

// AFilterableStaticMeshActor::AFilterableStaticMeshActor(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
// {
//     UE_LOG(LogTemp, Warning, TEXT("Thing created!!!!"))
// }

void AFilterableStaticMeshActor::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Began play!!!!!!!!"));

    HiddenDueToFilterSetting = false;
    DefaultMaterial = GetStaticMeshComponent()->GetMaterial(0);

    switch (UVInteraction)
    {
        case FilterVisibility::Visible:
            GetStaticMeshComponent()->SetVisibility(false);
            break;
        case FilterVisibility::Hidden:
            GetStaticMeshComponent()->SetVisibility(true);
            break;
        default:
            break;
    }
}

// Any
void AFilterableStaticMeshActor::OnAnyPhoto_Implementation()
{
}
void AFilterableStaticMeshActor::OnAnyPhotoFinished_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Photo finished!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("photo finished rn"));

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

// Thermal
void AFilterableStaticMeshActor::OnThermalPhoto_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Taking thermal photo!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("taking thermal photo rn"));

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
}

// UV
void AFilterableStaticMeshActor::OnUVPhoto_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Taking uv photo!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("taking uv photo rn"));

    switch (UVInteraction)
    {
    case FilterVisibility::Visible:
        GetStaticMeshComponent()->SetVisibility(true);
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
        GetStaticMeshComponent()->SetVisibility(false);
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
    UE_LOG(LogTemp, Warning, TEXT("Taking xray photo!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("taking xray photo rn"));

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
}
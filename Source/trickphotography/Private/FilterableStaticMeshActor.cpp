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
}

void AFilterableStaticMeshActor::OnPhotoFinished_Implementation()
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

void AFilterableStaticMeshActor::OnUVPhoto_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Taking thermal photo!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("taking uv photo rn"));
}
void AFilterableStaticMeshActor::OnXrayPhoto_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Taking thermal photo!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("taking xray photo rn"));
}
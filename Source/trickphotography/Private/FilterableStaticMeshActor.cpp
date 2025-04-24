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

    DefaultMaterial = GetStaticMeshComponent()->GetMaterial(0);
}

void AFilterableStaticMeshActor::OnThermalPhoto_Implementation() {
    UE_LOG(LogTemp, Warning, TEXT("Taking thermal photo!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("taking thermal photo rn"));
    GetStaticMeshComponent()->SetMaterial(0, ThermalMaterial);
}

void AFilterableStaticMeshActor::OnPhotoFinished_Implementation() {
    UE_LOG(LogTemp, Warning, TEXT("Photo finished!!!"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("photo finished rn"));
    GetStaticMeshComponent()->SetMaterial(0, DefaultMaterial);
}
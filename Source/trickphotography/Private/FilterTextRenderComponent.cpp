// Fill out your copyright notice in the Description page of Project Settings.


#include "FilterTextRenderComponent.h"

void UFilterTextRenderComponent::BeginPlay()
{
    Super::BeginPlay();
    SetVisibility(VisibleByPlayer);
}

void UFilterTextRenderComponent::OnAnyPhotoFinished_Implementation()
{
    SetVisibility(VisibleByPlayer);
}

void UFilterTextRenderComponent::OnThermalPhoto_Implementation()
{
    SetVisibility(VisibleInThermal);
}

void UFilterTextRenderComponent::OnUVPhoto_Implementation()
{
    SetVisibility(VisibleInUV);
}

void UFilterTextRenderComponent::OnXrayPhoto_Implementation()
{
    SetVisibility(VisibleInXray);
}
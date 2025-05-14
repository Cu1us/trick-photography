// Fill out your copyright notice in the Description page of Project Settings.

#include "FilterActor.h"
#include "FilterableInterface.h"

// Called when the game starts or when spawned
void AFilterActor::BeginPlay()
{
	Super::BeginPlay();
	FilterableComponents = GetComponentsByInterface(UFilterableInterface::StaticClass());
}

void AFilterActor::SetPPMHighlight(PPMHighlightType type)
{
	uint8 depthStencil = static_cast<uint8>(type);
	for (UActorComponent *component : GetComponents())
	{
		UPrimitiveComponent *primComponent = Cast<UPrimitiveComponent>(component);
		if (primComponent)
		{
			primComponent->bRenderCustomDepth = true;
			primComponent->CustomDepthStencilValue = depthStencil;
		}
	}
}

// Any
void AFilterActor::OnAnyPhoto_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnAnyPhoto(Cast<UObject>(filterableComponent));
		}
	}
}
void AFilterActor::OnAnyPhotoFinished_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnAnyPhotoFinished(Cast<UObject>(filterableComponent));
		}
	}
}

// Thermal
void AFilterActor::OnThermalPhoto_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnThermalPhoto(Cast<UObject>(filterableComponent));
		}
	}
}
void AFilterActor::OnThermalPhotoFinished_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnThermalPhotoFinished(Cast<UObject>(filterableComponent));
		}
	}
}

// UV
void AFilterActor::OnUVPhoto_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnUVPhoto(Cast<UObject>(filterableComponent));
		}
	}
}
void AFilterActor::OnUVPhotoFinished_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnUVPhotoFinished(Cast<UObject>(filterableComponent));
		}
	}
}

// X-Ray
void AFilterActor::OnXrayPhoto_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnXrayPhoto(Cast<UObject>(filterableComponent));
		}
	}
}
void AFilterActor::OnXrayPhotoFinished_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			filterableComponent->Execute_OnXrayPhotoFinished(Cast<UObject>(filterableComponent));
		}
	}
}
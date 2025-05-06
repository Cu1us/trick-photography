// Fill out your copyright notice in the Description page of Project Settings.

#include "FilterPawn.h"
#include "FilterableInterface.h"


// Called when the game starts or when spawned
void AFilterPawn::BeginPlay()
{
	Super::BeginPlay();
	FilterableComponents = GetComponentsByInterface(UFilterableInterface::StaticClass());
}

// Any
void AFilterPawn::OnAnyPhoto_Implementation()
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
void AFilterPawn::OnAnyPhotoFinished_Implementation()
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
void AFilterPawn::OnThermalPhoto_Implementation()
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
void AFilterPawn::OnThermalPhotoFinished_Implementation()
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
void AFilterPawn::OnUVPhoto_Implementation()
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
void AFilterPawn::OnUVPhotoFinished_Implementation()
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
void AFilterPawn::OnXrayPhoto_Implementation()
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
void AFilterPawn::OnXrayPhotoFinished_Implementation()
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
// Fill out your copyright notice in the Description page of Project Settings.

#include "FilterActor.h"
#include "FilterableInterface.h"

// Sets default values
/*AFilterActor::AFilterActor()
{
}*/

// Called when the game starts or when spawned
void AFilterActor::BeginPlay()
{
	Super::BeginPlay();
	FilterableComponents = GetComponentsByInterface(UFilterableInterface::StaticClass());
}

// Any
void AFilterActor::OnAnyPhoto_Implementation()
{
	for (UActorComponent *component : FilterableComponents)
	{
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{	
			filterableComponent->Execute_OnAnyPhoto(this);
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
			filterableComponent->Execute_OnAnyPhotoFinished(this);
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
			filterableComponent->Execute_OnThermalPhoto(this);
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
			filterableComponent->Execute_OnThermalPhotoFinished(this);
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
			filterableComponent->Execute_OnUVPhoto(this);
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
			filterableComponent->Execute_OnUVPhotoFinished(this);
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
			filterableComponent->Execute_OnXrayPhoto(this);
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
			filterableComponent->Execute_OnXrayPhotoFinished(this);
		}
	}
}
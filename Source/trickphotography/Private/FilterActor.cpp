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
// 	FString log = GetName();
// 	int len = FilterableComponents.Num();
// 	UE_LOG(LogTemp, Warning, TEXT("OnAnyPhoto run start on component: %s, TArray length: %d"), *log, len);
	for (UActorComponent *component : FilterableComponents)
	{
		// if (Cast<AFilterActor>(component)) {
		// 	UE_LOG(LogTemp, Warning, TEXT("Cancelled because component is AFilterActor"));
		// 	continue;
		// }
		IFilterableInterface *filterableComponent = Cast<IFilterableInterface>(component);
		if (filterableComponent)
		{
			// FString log2 = component->GetName();
			// UE_LOG(LogTemp, Warning, TEXT("Running OnAnyPhoto on component: %s"), *log2);
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
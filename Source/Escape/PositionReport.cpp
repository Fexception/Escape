// Fill out your copyright notice in the Description page of Project Settings.

#include "Escape.h"
#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FVector ObjectPos = GetOwner()->GetActorLocation();
	FString ObjectPosText = ObjectPos.ToString();

	// Create FString to store ObjectName, GetOwner is a pointer, 
	// We looked through it for GetName, which returns the name.
	FString ObjectName = GetOwner()->GetName(); 
	// Write to the log, %s (format operator) is a placeholder for the objectname as it is in the world view,
	// Uses *ObjectName as a dereference, the * is because UE_LOG is expecting
	// a TCHAR array, and the * converts the string to this type.
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPosText);
	// ...
	
}


// Called every frame
void UPositionReport::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
}


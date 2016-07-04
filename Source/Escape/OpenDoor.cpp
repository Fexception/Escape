// Fill out your copyright notice in the Description page of Project Settings.

#include "Escape.h"
#include "OpenDoor.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	PawnThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	
	// ...
	
}

void UOpenDoor::OpenDoor()
{
	
	//Create a rotator.
	//FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
	//Set door rotation.
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	
	//Create a rotator.
	//FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
	//Set door rotation.
	Owner->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the trigger volume every frame
	if (!PressurePlate) { return; }
	if (PressurePlate->IsOverlappingActor(PawnThatOpens) || GetTotalMassOfActorsOnPlate() > 50.f) {

		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	} else{
		CloseDoor();
	}
	//Check if its time to close the door

	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {
	float TotalMass = 0.f;

	//Find all the overlapping actors
	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	//Iterate through them adding their masses.
	for (const auto& Actor : OverlappingActors) {
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}

	return TotalMass;
}


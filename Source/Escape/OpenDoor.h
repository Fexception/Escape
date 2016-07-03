// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"
#define OUT

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	

private:
	UPROPERTY(VisibleAnywhere)
	AActor* PawnThatOpens;
	//The following means these properties are visible in the "Inspector"
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 90.0f;

	//The following means these properties are editable in the Inspector.
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	//Pawn inherits from actor, can use actor instead (like a player)
	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens; 
	float DoorCloseDelay = 1.f;
	float LastDoorOpenTime;
	AActor* Owner; //The owning actor

	float GetTotalMassOfActorsOnPlate();
	
};

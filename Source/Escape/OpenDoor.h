// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"
#define OUT

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

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

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpenRequest;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnCloseRequest;

private:
	UPROPERTY(VisibleAnywhere)
	AActor* PawnThatOpens = nullptr;
	//The following means these properties are visible in the "Inspector"

	//The following means these properties are editable in the Inspector.
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	//Pawn inherits from actor, can use actor instead (like a player)
	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens = nullptr; 

	AActor* Owner = nullptr; //The owning actor

	float GetTotalMassOfActorsOnPlate();

	float TriggerMass = 30.f;
	
};

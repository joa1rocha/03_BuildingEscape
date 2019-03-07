// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// This variable becomes globally set (not obvious to me at this point)
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	// Find owner
	Owner = GetOwner();
}

void UOpenDoor::OpenDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GlobalTime = GetWorld()->GetTimeSeconds();

	// Pole the Trigger Volume
	// If the ActorThatOpens is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		OpenDoor();
	}
	
	// Check if it is time to close the door
	if ((GlobalTime - LastDoorOpenTime) > DoorCloseDelay)
	{
		CloseDoor();
	}
}


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

	// This actor become globally set (not obvious to me at this point)
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// Find owner
	AActor* Owner = GetOwner();

	// Create Rotator
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{
	// Find owner
	AActor* Owner = GetOwner();

	// Create Rotator
	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Pool the Trigger Volume
	// If the ActorThatOpens is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
	else {
		CloseDoor();
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

void UOpenDoor::OpenDoor()
{
	// Find owner
	AActor* Owner = GetOwner();

	// Create Rotator
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);
}

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 90.0f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	AActor* ActorThatOpens; // Remember pawn inherits from actor
};

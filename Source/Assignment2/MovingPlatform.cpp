// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// #include "Customizations/MathStructProxyCustomizations.h"
// #include "Developer/Datasmith/DatasmithFacade/Public/DatasmithFacadeAnimation.h"
// #include "Iris/ReplicationSystem/NetObjectFactory.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

// Called to bind functionality to input
void AMovingPlatform::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(StartLocation,GetActorLocation());
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{	
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	} else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation+=(PlatformVelocity*DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity*DeltaTime);
}


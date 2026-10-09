// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ASSIGNMENT2_API AMovingPlatform : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector PlatformVelocity = FVector(100.0f, 0.0f, 0.0f);
	
	UPROPERTY(EditAnywhere, Category = "Moving")
	float MoveDistance = 100.0f;
	
	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity = FRotator(0.0f, 0.0f, 0.0f);
	
	FVector StartLocation;
	
	float GetDistanceMoved() const;
	void MovePlatform(float);
	void RotatePlatform(float);
	
	bool ShouldPlatformReturn() const;
};

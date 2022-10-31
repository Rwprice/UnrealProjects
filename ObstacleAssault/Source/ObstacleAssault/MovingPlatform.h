// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	
	FVector InitialActorLocation;
	FVector OriginPointForCurrentPath;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxDistance = 1000;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MaxVelocity;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

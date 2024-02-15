// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEPROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 InputA = 3.2;

	UPROPERTY(EditAnywhere)
	int32 InputB = 0;

	UPROPERTY(EditAnywhere)
	int32 APlusB = 0;

	UPROPERTY(EditAnywhere)
	float MyFloat = 5.99;

	UPROPERTY(EditAnywhere)
	bool MyBool = true;

	UPROPERTY(EditAnywhere)
	float float1 = 32.25;

	UPROPERTY(EditAnywhere)
	float float2 = 10.2;

	UPROPERTY(EditAnywhere)
	float float1float2 = 0;

	UPROPERTY(EditAnywhere)
	FVector MyVector;

	UPROPERTY(EditAnywhere)
	float MyX = 0;

	UPROPERTY(EditAnywhere)
	FVector Vector2 = FVector(1, 2, 3);

	UPROPERTY(EditAnywhere)
	float newAux=0;

	FVector movingPlatformLocation;

	UPROPERTY(EditAnywhere)
	AActor *player;

	UPROPERTY(EditAnywhere)
	float speedPlat = 1;

	UPROPERTY(EditAnywhere)
	FVector firstPos = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere)
	FVector endPos = FVector(0, 0, 0);

	void ChangePos();

	void UpdatePosfowardPlayer();


};



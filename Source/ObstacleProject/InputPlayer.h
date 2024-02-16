// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputPlayer.generated.h"

UCLASS()
class OBSTACLEPROJECT_API AInputPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AInputPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//mapping
	UPROPERTY(EditAnywhere, Category ="EnhancedInput")
	class UInputMappingContext* InputMapping;

	//input action
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* TestAction;

	void TestInput();

private:
	void AddInputMapping();

};

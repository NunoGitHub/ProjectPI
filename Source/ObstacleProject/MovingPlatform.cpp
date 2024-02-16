// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	firstPos = MyVector = GetActorLocation();
	endPos = FVector(firstPos.X + 1000, firstPos.Y, firstPos.Z);

	//acess variables that we created in yhe header file
	MyInt = 9;

	APlusB = InputA + InputB;

	// testing float
	float1float2 = float1 + float2;

	//
	MyX = MyVector.X;

	//
	//ChangePos();

	/*movingPlatformLocation= player->GetActorLocation();

	SetActorLocation(movingPlatformLocation);*/

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*MyVector.Y += speedPlat;

	SetActorLocation(MyVector);*/

	//UpdatePosfowardPlayer();

	//Move Platform foward
	//get current location
	FVector CurrentLocation = GetActorLocation();
	//get distance
	float distanceTravelled = FVector::Dist(firstPos, CurrentLocation);
	// Print or use the distance as needed
	UE_LOG(LogTemp, Warning, TEXT("Distance Traveled: %f"), distanceTravelled);

	// move platform from first pos to final

	FVector direction = (endPos - CurrentLocation).GetSafeNormal();
	CurrentLocation += direction * speedPlat * DeltaTime;

	SetActorLocation(CurrentLocation);
	//ola
	// Mensagem a ser exibida

	//convert float to string
	float a = FVector::Dist(CurrentLocation, endPos);

	// get number digits
	int size = snprintf(NULL, 0, "%f", a);

	char *disS = (char*) malloc(size+1);

	snprintf(disS, size + 1, "%f", a);

	//FString Message(GetName() +"-> " + disS);

	float DisplayTime = 2.0f;
	FColor Color = FColor::Green;
	int32 Key = 0;
	//GEngine->AddOnScreenDebugMessage(Key, DisplayTime, Color, GetName() + "-> " + disS);
	free(disS);
	//check if the platform has already traveled the maximum distance
	if (FVector::Dist(CurrentLocation, endPos) <=1.0f) {
		FVector Temp = firstPos;
		firstPos = endPos;
		endPos = Temp;
	}

}

void AMovingPlatform::ChangePos()
{
	//add new value and change position of x and y 
	Vector2.X = newAux;
	float auxX = Vector2.X;
	Vector2.X = Vector2.Y;
	Vector2.Y = auxX;
}
void AMovingPlatform::UpdatePosfowardPlayer() {

	// get player location
	FVector CurrentLocation = player->GetActorLocation();

	// calculate new foward position + distance
	FVector NewLocation = CurrentLocation + player->GetActorForwardVector() * 160;

	// send new position to platform 
	SetActorLocation(NewLocation);
}

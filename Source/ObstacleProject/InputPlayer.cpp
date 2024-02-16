
#include "InputPlayer.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>

// Sets default values
AInputPlayer::AInputPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInputPlayer::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AInputPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddInputMapping();
}

// Called to bind functionality to input
void AInputPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//for key pressed
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		Input->BindAction(TestAction, ETriggerEvent::Triggered, this, &AInputPlayer::TestInput);
	}

}

void AInputPlayer::TestInput()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "key pressed input action");
}

void AInputPlayer::AddInputMapping()
{
	//add input mapping
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller)) {
		//get local player subsistem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			//add input context
			//0 is the highest priority, will block input of lower priority
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}


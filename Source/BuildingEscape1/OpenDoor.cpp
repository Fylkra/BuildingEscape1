// No Rights Reserved. 


#include "OpenDoor.h"
#include "Math/Rotator.h"
#include "Engine/World.h"


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

	// Get Player Controller
	ActorThatActivates = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenDoor::OpenDoor()
{
	// Get Owner
	Owner = GetOwner();

	// Create Rotator
	NewRotation = FRotator(0.f, OpenAngle, 0.f);

	// Set Rotation on Door
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume: If Actor is in TriggerVolume
	if (DoorTrigger->IsOverlappingActor(ActorThatActivates))
	{
		OpenDoor();
	}
}


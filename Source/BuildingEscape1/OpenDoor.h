// No Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE1_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

	AActor* Owner;

	FRotator NewRotation;

private:
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* DoorTrigger;


	AActor* ActorThatActivates;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};

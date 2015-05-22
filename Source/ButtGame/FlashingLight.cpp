// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtGame.h"
#include "FlashingLight.h"


// Sets default values
AFlashingLight::AFlashingLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//spawn the point light
	FActorSpawnParameters SpawnInfo;
	//theLight = GetWorld()->SpawnActor<UPointLightComponent>(UPointLightComponent::StaticClass(), SpawnInfo);
	theLight = CreateDefaultSubobject<UPointLightComponent>("theLight");
	theLight->AttachTo(RootComponent);
	SetFlashingRate(flashingRate);
}

// Called when the game starts or when spawned
void AFlashingLight::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFlashingLight::SetFlashingRate(float newFlashingRate) {
	flashingRate = newFlashingRate;
	currentTime = 0;
}

// Called every frame
void AFlashingLight::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	currentTime += DeltaTime;
	if (currentTime > flashingRate) {
		currentTime -= flashingRate;
		direction = !direction;
	}

	float newIntensity = currentTime / flashingRate * maxBrightness;
	if (!direction) newIntensity = (1 - (currentTime / flashingRate)) * maxBrightness;

	if (currentTime == 0 && direction) newIntensity = 0;
	if (currentTime == 0 && !direction) newIntensity = maxBrightness;

	theLight->SetIntensity(newIntensity);
}


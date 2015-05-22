// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FlashingLight.generated.h"

UCLASS()
class BUTTGAME_API AFlashingLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashingLight();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void SetFlashingRate(float newFlashingRate);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
		float maxBrightness = 100000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
		float flashingRate = 2;

	float nextChangeTime = 0;
	float currentTime = 0;
	bool direction = true;
	int tickCounter = 0;

	UPointLightComponent* theLight;

};

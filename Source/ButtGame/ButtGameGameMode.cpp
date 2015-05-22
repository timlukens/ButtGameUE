// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ButtGame.h"
#include "ButtGameGameMode.h"
#include "ButtGameCharacter.h"

AButtGameGameMode::AButtGameGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Mixamo_Kachujin/Mixamo_Kachujin"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
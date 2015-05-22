// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EquipableWeapon.h"
#include "EquipableWeaponLongSword.generated.h"

/**
 * 
 */
UCLASS()
class BUTTGAME_API AEquipableWeaponLongSword : public AEquipableWeapon
{
	GENERATED_BODY()
	
	UPROPERTY()
		UBoxComponent* boxComponent;

public:
	AEquipableWeaponLongSword();
	virtual void AttackWeak();
};

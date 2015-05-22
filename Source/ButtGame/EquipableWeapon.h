// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EquipableWeapon.generated.h"

UCLASS()
class BUTTGAME_API AEquipableWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEquipableWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	//Equips
	virtual bool AttachWeaponToPawn(APawn* WeaponOwner, FString SkeletalCompName);
	virtual USkeletalMeshComponent* GetPawnSkeletalComp(FString ComponentName);

	APawn* OwningPawn;
	USkeletalMeshComponent* ArmMesh;

	//attack n shit
	UAnimMontage* WeakAttackAnim;
	bool isAttacking;
	virtual void AttackWeak();

	bool PlayAnimMontage(class UAnimMontage* animMontage, float inPlayRate);

	UFUNCTION(BlueprintCallable, Category = "AnimNotifies")
	virtual void AttackAnimFinished();

	void ReceiveActorBeginOverlap(AActor* otherActor);
	
};

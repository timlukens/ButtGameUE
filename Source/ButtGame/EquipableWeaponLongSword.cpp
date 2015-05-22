// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtGame.h"
#include "EquipableWeaponLongSword.h"
#include "Animation/AnimMontage.h"
#include "FlashingLight.h"


AEquipableWeaponLongSword::AEquipableWeaponLongSword() : Super() {
	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//And now our cylinder
	UStaticMeshComponent* cylinderVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	cylinderVisual->AttachTo(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> cylinderVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (cylinderVisualAsset.Succeeded())
	{
		cylinderVisual->SetStaticMesh(cylinderVisualAsset.Object);
		cylinderVisual->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		cylinderVisual->SetWorldScale3D(FVector(0.1f, 0.1f, 2.0f));
		cylinderVisual->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	SetActorEnableCollision(true);

	ConstructorHelpers::FObjectFinder<UAnimMontage> anim(TEXT("/Game/ThirdPerson/Mixamo_Kachujin/Anims/PlayerAttackWeakLongSword"));
	WeakAttackAnim = anim.Object;
}

void AEquipableWeaponLongSword::AttackWeak() {
	if (isAttacking) return;
	if (!WeakAttackAnim) {
		UE_LOG(LogTemp, Warning, TEXT("EquipableWeapon: Couldn't find montage"));
		return;
	}

	if (!Super::PlayAnimMontage(WeakAttackAnim, 0.6f)) {
		UE_LOG(LogTemp, Warning, TEXT("EquipableWeapon: Didn't play montage"));
	}

	//TArray<AActor*> BaseFrameArray;
	//UGameplayStatics::GetAllActorsOfClass(this->GetWorld(), AFlashingLight::StaticClass(), BaseFrameArray);

	//AFlashingLight* theLight = Cast<AFlashingLight>(BaseFrameArray[0]);

	//theLight->SetFlashingRate(-1);
}
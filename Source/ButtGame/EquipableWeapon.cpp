// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtGame.h"
#include "EquipableWeapon.h"
#include "Animation/AnimInstance.h"


// Sets default values
AEquipableWeapon::AEquipableWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	isAttacking = false;
}

// Called when the game starts or when spawned
void AEquipableWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquipableWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool AEquipableWeapon::AttachWeaponToPawn(APawn* WeaponOwner, FString SkeletalCompName)
{
	UE_LOG(LogTemp, Warning, TEXT("Trying to attach weapon"));
	OwningPawn = WeaponOwner; // Sets the owner of this weapon. (Note: OwningPawn  is a APawn* member in my weapon class.)
	SetOwner(OwningPawn); // AActor::SetOwner(APawn*);

	// A method i created to get any skeletal component from the owning pawn. (Could be made a template to function to get any type.)
	ArmMesh = GetPawnSkeletalComp(SkeletalCompName);

	if (ArmMesh) // Check to see if our rig Skeletal Mesh Component is good.
	{
		UE_LOG(LogTemp, Warning, TEXT("Found ArmMesh"));
		// AActor::AttachRootComponentTo(..)
		AttachRootComponentTo(ArmMesh, FName(TEXT("weapon_socket_r")), EAttachLocation::SnapToTarget); // Attach the root component of our Weapon actor to the ArmMesh at the location of the socket.
		return true; // Note: We can only assume it is attached, since epic did not provide a return value.
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Did NOT find ArmMesh"));
		return false;
	}
}

USkeletalMeshComponent* AEquipableWeapon::GetPawnSkeletalComp(FString ComponentName)
{
	TArray<UActorComponent*> Components; // Array for Pawns components
	USkeletalMeshComponent* ArmMesh = NULL; // Will hold the skeletal mesh we want

	if (OwningPawn)
		OwningPawn->GetComponents(Components); // Get the components from the owning pawn

	for (UActorComponent* Comp : Components)
	{
		ArmMesh = Cast<USkeletalMeshComponent>(Comp); // Cast any component to Skeletal Comp.
		if (ArmMesh) // If we have a skeletal mesh
		{
			UE_LOG(LogTemp, Warning, TEXT("Found mesh: %s"), *ArmMesh->GetName());
			if (ArmMesh->GetName() == ComponentName) {
				UE_LOG(LogTemp, Warning, TEXT("Returning ArmMesh"));
				return ArmMesh;
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Could NOT return ArmMesh"));
	return NULL; // Finished with out finding the component we wanted.
}

bool AEquipableWeapon::PlayAnimMontage(class UAnimMontage* animMontage, float inPlayRate)
{
	UE_LOG(LogTemp, Warning, TEXT("EquipableWeapon: Trying to play animation"));
	if(!ArmMesh) return false;
	if (animMontage && ArmMesh && ArmMesh->AnimScriptInstance)
	{
		isAttacking = true;
		return (ArmMesh->AnimScriptInstance->Montage_Play(animMontage, inPlayRate) > 0 ? true : false);
	}

	return false;
}

void AEquipableWeapon::AttackWeak() {

}

void AEquipableWeapon::AttackAnimFinished() {
	UE_LOG(LogTemp, Warning, TEXT("EquipableWeapon: Attack finished"));
	isAttacking = false;
}

void AEquipableWeapon::ReceiveActorBeginOverlap(AActor* otherActor) {
	//UE_LOG(LogTemp, Warning, TEXT("EquipableWeapon: Just overlapped actor: %s"), otherActor->GetName());
	UE_LOG(LogTemp, Warning, TEXT("EquipableWeapon: Just overlapped actor"));
}





// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//class UTankAimingComponent;
//class UTankBarrel; //Forward Declaration
//class AProjectile;
//class UTankMovementComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//void AimAt(FVector hitLocation);


	/*
		UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret * turretToSet);
	*/

	/*
		UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	float reloadTimeInSeconds = 3;
	*/
	UFUNCTION(BlueprintPure, Category = Health)
		float GetHealthPercent() const;

	FTankDelegate OnDeath;


protected:

	/*
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* tankAimingComponent = nullptr;
	

	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* tankMovementComponent = nullptr;
	*/
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;



private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//virtual void Tick() override;
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// TODO remove once firing is moved to aiming component

	/*
		UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 1000000; // TODO find Sensible starting value.
	*/

	//UTankBarrel* meshToBarrel(UStaticMeshComponent*);

	/*
		UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	// local barrel reference for spawning projectile
	UTankBarrel* barrel = nullptr;
	
	double lastFireTime = 0;
	*/
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		int32 startingHealth = 100;
	
	UPROPERTY(VisibleAnywhere, Category = Setup)
	int32 currentHealth = startingHealth;
};

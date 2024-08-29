// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterCharacter.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Pitch"), this, &AShooterCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AShooterCharacter::LookRight);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AShooterCharacter::Jump);
}

void AShooterCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value, IsMoveInputIgnored());
}

void AShooterCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value, IsMoveInputIgnored());
}

void AShooterCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AShooterCharacter::LookRight(float value)
{
	AddControllerYawInput(value);
}

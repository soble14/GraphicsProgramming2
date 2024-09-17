// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAICharacter.h"
#include "Enemy/EnemyAIController.h"
#include "Collectable/Coin.h"

// Sets default values
AEnemyAICharacter::AEnemyAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AEnemyAIController::StaticClass();

	static ConstructorHelpers::FClassFinder<AActor>CoinBP(TEXT("/Game/Blueprint/Collectable/BP_Coin"));
	if (CoinBP.Succeeded())
	{
		BP_Coin = CoinBP.Class;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BP_Coin not found!"));
	}
}

// Called when the game starts or when spawned
void AEnemyAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemyAICharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;

	if (Health <= 0) 
	{
		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = FRotator::ZeroRotator;

		GetWorld()->SpawnActor<AActor>(BP_Coin, SpawnLocation, SpawnRotation);

		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Enemy Died"));
	}
	return DamageAmount;
}

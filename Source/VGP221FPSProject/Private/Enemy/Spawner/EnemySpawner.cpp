// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Spawner/EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (NavArea) {
		AEnemyAICharacter* EnemyOwner = Cast<AEnemyAICharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		NavArea->K2_GetRandomReachablePointInRadius(GetWorld(), EnemyOwner->GetActorLocation(), RandomLocation, 2000.0f);
	}
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::RunTriggerableTimer()
{

}
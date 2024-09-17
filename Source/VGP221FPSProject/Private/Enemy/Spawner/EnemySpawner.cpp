// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Spawner/EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (EnemyClasses.Num() != MaxEnemiesPerClass.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("EnemyClasses and MaxEnemiesPerClass arrays are out of sync!"));
		return;
	}

	for (int32 i = 0; i < EnemyClasses.Num(); i++)
	{
		SpawnedEnemiesPerClass.Add(0);
	}
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimer, this, &AEnemySpawner::SpawnEnemy, SpawnInterval, true);
	UE_LOG(LogTemp, Warning, TEXT("Spawn timer initialized with interval: %f"), SpawnInterval);

}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpawner::SpawnEnemy()
{
	int32 TotalSpawnedEnemies = 0;

	for (int32 i = 0; i < EnemyClasses.Num(); i++)
	{
		int32 SpawnedEnemies = SpawnedEnemiesPerClass[i];
		int32 MaxEnemies = MaxEnemiesPerClass.IsValidIndex(i) ? MaxEnemiesPerClass[i] : 0;
		TotalSpawnedEnemies += SpawnedEnemies;

		if (SpawnedEnemies < MaxEnemies && EnemyClasses[i])
		{
			FVector SpawnLocation = GetRandomLocation();
			FActorSpawnParameters SpawnParams;

			SpawnLocation.Z += 100.0f;

			ACharacter* SpawnedEnemy = GetWorld()->SpawnActor<ACharacter>(EnemyClasses[i], SpawnLocation, FRotator::ZeroRotator, SpawnParams);

			if (SpawnedEnemy) 
			{
				SpawnedEnemy->SpawnDefaultController();
				SpawnedEnemiesPerClass[i]++;
			}
		}
	}

	if (TotalSpawnedEnemies >= TotalMaxEnemies)
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimer);
		UE_LOG(LogTemp, Warning, TEXT("Reached total spawn Limit"));
	}
}

FVector AEnemySpawner::GetRandomLocation()
{
	FVector Origin = GetActorLocation();
	FNavLocation ResultLocation;
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (NavSystem)
	{
		NavSystem->GetRandomReachablePointInRadius(Origin, 50000.0f, ResultLocation);
		return ResultLocation.Location;
	}

	return FVector();
}

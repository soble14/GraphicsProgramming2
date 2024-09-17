// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI/NavigationSystemBase.h"
#include "NavigationSystem.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"
#include "Enemy/EnemyAICharacter.h"
#include "EnemySpawner.generated.h"

UCLASS()
class VGP221FPSPROJECT_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnInterval = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	int32 TotalMaxEnemies = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TArray<TSubclassOf<ACharacter>> EnemyClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TArray<int32> MaxEnemiesPerClass;

private:
	FTimerHandle SpawnTimer;

	void SpawnEnemy();

	FVector GetRandomLocation();

	TArray<int32> SpawnedEnemiesPerClass;
};

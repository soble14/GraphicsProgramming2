// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
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

	UPROPERTY()
	FVector RandomLocation;
	UPROPERTY()
	UNavigationSystemV1* NavArea;
	UPROPERTY()
	FTimerHandle RetriggerableTimerHandle;

	UFUNCTION()
	void RunTriggerableTimer();
};

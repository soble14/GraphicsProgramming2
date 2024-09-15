// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "kismet/GameplayStatics.h"
#include "LevelTransition.generated.h"

UCLASS()
class VGP221FPSPROJECT_API ALevelTransition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelTransition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MainMenuLevel();

	UFUNCTION()
	void GameLevel();

	UFUNCTION()
	void VictoryLevel();

	UFUNCTION()
	void DefeatLevel();

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelTransition.h"

// Sets default values
ALevelTransition::ALevelTransition()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelTransition::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelTransition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelTransition::MainMenuLevel()
{
}

void ALevelTransition::GameLevel()
{
}

void ALevelTransition::VictoryLevel()
{
}

void ALevelTransition::DefeatLevel()
{
}


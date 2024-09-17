// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameModeBase.h"

void AMainMenuGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Main Menu/Victory/Defeat Game Mode started"));
}

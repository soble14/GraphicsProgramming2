// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GUI/Levels/MainMenu.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FPSPROJECT_API AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
};

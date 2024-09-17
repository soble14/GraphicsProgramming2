// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainMenuHUD.h"

void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MainMenuWidgetClass)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);
        if (CurrentWidget)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

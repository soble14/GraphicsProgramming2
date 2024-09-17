// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/MenuWidget.h"

void UMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    FString CurrentLevelName = GetWorld()->GetMapName();

    if (CurrentLevelName.Contains("MainMenuLevel"))
    {
        TopText->SetText(FText::FromString("Main Menu"));

        PlayButtonText->SetText(FText::FromString("Play Game"));
        QuitButtonText->SetText(FText::FromString("Quit"));

        PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::OnPlayGameClicked);
        QuitButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitClicked);
    }
    else if (CurrentLevelName.Contains("VictoryLevel"))
    {
        TopText->SetText(FText::FromString("Victory!"));

        PlayButtonText->SetText(FText::FromString("Play Again"));
        QuitButtonText->SetText(FText::FromString("Quit"));

        PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::OnPlayAgainClicked);
        QuitButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitClicked);
    }
    else if (CurrentLevelName.Contains("DefeatLevel"))
    {
        TopText->SetText(FText::FromString("Defeat"));

        PlayButtonText->SetText(FText::FromString("Retry"));
        QuitButtonText->SetText(FText::FromString("Quit"));

        PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::OnRetryClicked);
        QuitButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitClicked);
    }
}

void UMenuWidget::OnPlayGameClicked()
{
    UGameplayStatics::OpenLevel(GetWorld(), "GameMap");
}

void UMenuWidget::OnPlayAgainClicked()
{
    UGameplayStatics::OpenLevel(GetWorld(), "GameMap");
}

void UMenuWidget::OnRetryClicked()
{
    UGameplayStatics::OpenLevel(GetWorld(), "GameMap");
}

void UMenuWidget::OnQuitClicked()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand("quit");
    }
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/Levels/MainMenu.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	FString CurrentLevelName = GetWorld()->GetMapName();

	if (CurrentLevelName.Contains("MainMenuLevel"))
	{
		TopText->SetText(FText::FromString("MainMenu"));

		PlayButtonText->SetText(FText::FromString("Play Game"));
		QuitButtonText->SetText(FText::FromString("Quit"));

		PlayButton->OnClicked.AddDynamic(this, &UMainMenu::StartGame);
		QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	}
	else if (CurrentLevelName.Contains("VictoryLevel"))
	{
		TopText->SetText(FText::FromString("Victory"));

		PlayButtonText->SetText(FText::FromString("Play Again"));
		QuitButtonText->SetText(FText::FromString("Quit"));

		PlayButton->OnClicked.AddDynamic(this, &UMainMenu::StartGame);
		QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	}
	else if (CurrentLevelName.Contains("DefeatLevel"))
	{
		TopText->SetText(FText::FromString("Defeat"));

		PlayButtonText->SetText(FText::FromString("Retry"));
		QuitButtonText->SetText(FText::FromString("Quit"));

		PlayButton->OnClicked.AddDynamic(this, &UMainMenu::StartGame);
		QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	}
}

void UMainMenu::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), "GameMap");
}

void UMainMenu::PlayAgain()
{
	UGameplayStatics::OpenLevel(GetWorld(), "GameMap");
}

void UMainMenu::Retry()
{
	UGameplayStatics::OpenLevel(GetWorld(), "GameMap");
}

void UMainMenu::QuitGame()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController) 
	{
		PlayerController->ConsoleCommand("quit");
	}
}

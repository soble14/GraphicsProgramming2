// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "kismet/GameplayStatics.h"
#include "kismet/KismetSystemLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "HUD/FPSHUD.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FPSPROJECT_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText;

	UPROPERTY()
	class UTextBlock* PlayButtonText;

	UPROPERTY()
	class UTextBlock* QuitButtonText;

	UPROPERTY(meta = (BindWidget))
	class UButton* PlayButton;

	UPROPERTY(meta =(BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void PlayAgain();

	UFUNCTION()
	void Retry();

	UFUNCTION()
	void QuitGame();

};

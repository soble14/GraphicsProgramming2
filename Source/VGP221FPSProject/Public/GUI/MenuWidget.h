// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FPSPROJECT_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

public:
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TopText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PlayButtonText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* QuitButtonText;

    UPROPERTY(meta = (BindWidget))
    class UButton* PlayButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;

    UFUNCTION()
    void OnPlayGameClicked();

    UFUNCTION()
    void OnPlayAgainClicked();

    UFUNCTION()
    void OnRetryClicked();

    UFUNCTION()
    void OnQuitClicked();
};

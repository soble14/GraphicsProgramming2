// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"
#include "Widgets/SWeakWidget.h"

void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu(gameMenuWidget);
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	//1. Calculate the cetner point on the screen
	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	//2. Set the crosshair pivot to the center. This makes it center, without this it will be off center, it would be 0.5 units down and 0.5 units to the right.
	float CrosshairCenterWidth = (CrosshairTexture->GetSurfaceWidth() * 0.5f);
	float CrosshairCenterHeight = (CrosshairTexture->GetSurfaceHeight() * 0.5f);
	FVector2D CrosshairDrawPos(Center.X - CrosshairCenterWidth, Center.Y - CrosshairCenterHeight);

	//3. Draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPos, CrosshairTexture->GetResource(), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void AFPSHUD::ShowSettingMenu()
{
	if (GEngine && GEngine->GameViewport) {
		settingWidget = SNew(SSettingWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(menuWidgetContainer, SWeakWidget).PossiblyNullContent(settingWidget.ToSharedRef()));

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AFPSHUD::RemoveSettingMenu()
{
	if (GEngine && GEngine->GameViewport && menuWidgetContainer.IsValid()) {
		GEngine->GameViewport->RemoveViewportWidgetContent(menuWidgetContainer.ToSharedRef());
		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AFPSHUD::ShowMenu(TSubclassOf<UFPSUserWidget> newGameMenu)
{
	if (gameWidgetContainer) {
		gameWidgetContainer->RemoveFromParent();
		gameWidgetContainer = nullptr;
	}

	if (newGameMenu) {
		gameWidgetContainer = CreateWidget<UFPSUserWidget>(GetWorld(), newGameMenu);
		gameWidgetContainer->AddToViewport();
	}
}

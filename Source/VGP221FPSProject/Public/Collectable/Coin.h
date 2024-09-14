// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable/Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSHUD.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FPSPROJECT_API ACoin : public ACollectable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* CoinMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Points = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate = 100.0f;
	UPROPERTY()
	float OnCollectRotationRate = 1500.0f;

	FTimerHandle DeathTimerHandle;
	void DeathTimerComplete();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable/Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSHUD.h"
#include "Portal.h"
#include "KeyCollectable.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FPSPROJECT_API AKeyCollectable : public ACollectable
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AKeyCollectable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* KeyMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Keys = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate = 100.0f;
	UPROPERTY()
	float OnCollectRotationRate = 1500.0f;

	FTimerHandle DeathTimerHandle;
	void DeathTimerComplete();
};

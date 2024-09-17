// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/FPSCharacter.h"
#include "Portal.generated.h"

UCLASS()
class VGP221FPSPROJECT_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PortalMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerZone;

	UPROPERTY()
	int KeysCollected;

	UPROPERTY()
	int RequiredKeysToUnlock = 5;

	UFUNCTION()
	void AddKey();

	UFUNCTION()
	void Unlock();

	UFUNCTION()
	void OnPlayerEnterPortal(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	bool bIsUnlocked;
};

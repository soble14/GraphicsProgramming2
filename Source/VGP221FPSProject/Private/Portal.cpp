// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PortalMesh"));
	RootComponent = PortalMesh;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->SetupAttachment(PortalMesh);
	TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &APortal::OnPlayerEnterPortal);
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortal::AddKey()
{
	KeysCollected++;

	UE_LOG(LogTemp, Warning, TEXT("Portal has %d Keys"), KeysCollected);

	if (KeysCollected >= RequiredKeysToUnlock && !bIsUnlocked)
	{
		Unlock();
	}
}

void APortal::Unlock()
{
	bIsUnlocked = true;
	UE_LOG(LogTemp, Warning, TEXT("Portal is now unlocked"));
}

void APortal::OnPlayerEnterPortal(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bIsUnlocked)
	{
		AFPSCharacter* player = Cast<AFPSCharacter>(OtherActor);
		if (player)
		{
			UGameplayStatics::OpenLevel(this, FName("VictoryLevel"));
			UE_LOG(LogTemp, Warning, TEXT("Player has entered portal"));
		}
	}
}


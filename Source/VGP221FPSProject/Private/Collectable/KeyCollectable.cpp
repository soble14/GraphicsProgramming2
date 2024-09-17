// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable/KeyCollectable.h"

AKeyCollectable::AKeyCollectable()
{
	PrimaryActorTick.bCanEverTick = true;

	if (!KeyMeshComponent)
	{
		KeyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
		KeyMeshComponent->SetupAttachment(CollisionComponent);
	}
}

void AKeyCollectable::BeginPlay()
{
	Super::BeginPlay();
}

void AKeyCollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void AKeyCollectable::OnCollect()
{
	Super::OnCollect();

	RotationRate = OnCollectRotationRate;
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &AKeyCollectable::DeathTimerComplete, 0.5, false);

	APortal* portal = Cast<APortal>(UGameplayStatics::GetActorOfClass(GetWorld(), APortal::StaticClass()));
	if (portal)
	{
		portal->AddKey();
	}
}

void AKeyCollectable::DeathTimerComplete()
{
	AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
	if (HUD) {
		HUD->gameWidgetContainer->SetKeyText(Keys);
	}

	Destroy();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable/Collectable.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::BeginOverlap);
		CollisionComponent->InitSphereRadius(50.0f);
		RootComponent = CollisionComponent;
	}
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectable::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnCollect();
}

void ACollectable::OnCollect()
{
	UE_LOG(LogTemp, Warning, TEXT("Collectable OnCollect Called"))
}


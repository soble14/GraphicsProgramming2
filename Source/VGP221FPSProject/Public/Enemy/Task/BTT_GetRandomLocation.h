// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/EnemyAIController.h"
#include "BTT_GetRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FPSPROJECT_API UBTT_GetRandomLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	FVector RandomLocation;
	UNavigationSystemV1* NavArea;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

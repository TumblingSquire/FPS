// Fill out your copyright notice in the Description page of Project Settings.

#include "MyChooseNextWayPoint.h"
#include "AIController.h"
#include "Public/PatrolRoute.h" // TODO remove coupling PatrollingGuard
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMyChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	// Get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if(!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	// Warn against empty route point
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A Guard has no patrol points"));
	}

	// set next patrol point
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	// TODO protect against empty patrol routes
	return EBTNodeResult::Succeeded;
}




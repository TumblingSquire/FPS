// Fill out your copyright notice in the Description page of Project Settings.

#include "MyChooseNextWayPoint.h"
#include "AIController.h"
#include "Public/MyTP_ThirdPersonCharacter.h" // TODO remove coupling PatrollingGuard
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMyChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	// Get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<AMyTP_ThirdPersonCharacter>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

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




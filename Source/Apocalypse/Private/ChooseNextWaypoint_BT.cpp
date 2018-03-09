// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChooseNextWaypoint_BT.h"


EBTNodeResult::Type UChooseNextWaypoint_BT::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Execute C++ task report for duty!"));
	return EBTNodeResult::Succeeded;
}

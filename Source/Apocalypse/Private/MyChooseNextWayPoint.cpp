// Fill out your copyright notice in the Description page of Project Settings.

#include "MyChooseNextWayPoint.h"

EBTNodeResult::Type UMyChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Execute C++ task report for duty!"));
	return EBTNodeResult::Succeeded;
}




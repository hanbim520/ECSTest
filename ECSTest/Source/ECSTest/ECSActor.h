// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MassArchetypeTypes.h"
#include "MassEntityTypes.h"
#include <Engine/World.h>
#include <MassProcessor.h>

#include "ECSActor.generated.h"

USTRUCT()
struct FFloatFragment :public FMassFragment
{
	GENERATED_BODY()
		float Value;
};

USTRUCT()
struct FInt32Fragment :public FMassFragment
{
	GENERATED_BODY()
		float Value;
};

struct FMassTest 
{
	FMassArchetypeHandle Archetype1;
	FMassArchetypeHandle Archetype2;
	FMassArchetypeHandle Archetype3;

	TArray<FMassEntityHandle> Entities;

	class UMassEntitySubsystem* System;

	void Init(UWorld* World);


};

// 
// UCLASS()
// class UCusotmProcessor :public UMassProcessor
// {
// 	GENERATED_BODY()
// public:
// 	UCusotmProcessor() {};
// 	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)override
// 	{
// 		int32 Num = Context.GetNumEntities();
// 		TArrayView<FFloatFragment>Floats = Context.GetMutableFragmentView<FFloatFragment>();
// 		for (size_t i = 0; i < Num; ++i)
// 		{
// 				Floats[i].Value = 20.0f;
// 		}
// 	}
// 
// 
// 	virtual void ConfigureQueries() override
// 	{
// 		Query.AddRequirement<FFloatFragment>(EMassFragmentAccess::ReadWrite);
// 	}
// 
// 
// protected:
// 	FMassEntityQuery Query;
// 
// 
// };

UCLASS()
class ECSTEST_API AECSActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AECSActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

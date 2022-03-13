// Fill out your copyright notice in the Description page of Project Settings.


#include "ECSActor.h"
#include "MassEntitySubsystem.h"
#include "MassExecutor.h"


void FMassTest::Init(UWorld* World)
{
	System = UWorld::GetSubsystem<UMassEntitySubsystem>(World);

	const UScriptStruct* FragmentTypes[] = { FFloatFragment::StaticStruct(),FInt32Fragment::StaticStruct() };
	Archetype1 = System->CreateArchetype(MakeArrayView(&FragmentTypes[0], 1));
	Archetype2 = System->CreateArchetype(MakeArrayView(&FragmentTypes[1], 1));
	Archetype3 = System->CreateArchetype(FragmentTypes);

	System->BatchCreateEntities(Archetype1, 100, Entities);
	System->BatchCreateEntities(Archetype2, 200, Entities);
	System->BatchCreateEntities(Archetype3, 300, Entities);

// 	System->DestroyEntity(Entities[0]);
// 	Entities.RemoveAt(0);

// 	FMassExecutionContext Context;
// 	FMassEntityQuery Query;
// 	Query.AddRequirement<FFloatFragment>(EMassFragmentAccess::ReadWrite);
// 	Query.ForEachEntityChunk(*System, Context, [](FMassExecutionContext& Ctx)
// 		{
// 			int32 Num = Ctx.GetNumEntities();
// 			TArrayView<FFloatFragment> Floats = Ctx.GetMutableFragmentView<FFloatFragment>();
// 			for (int32 i = 0; i < Num; ++i)
// 			{
// 				Floats[i].Value = 20.0f;
// 			}
// 
// 
// 		});
// 	const auto Processor = NewObject<UCusotmProcessor>(System);
// 	FMassProcessingContext MassProcessingContext(*System,0.0f);
// 	UE::Mass::Executor::Run(*Processor, MassProcessingContext);
}

// Sets default values
AECSActor::AECSActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AECSActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AECSActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMassEntityTraitBase.h"
#include "MassEntityTemplateRegistry.h"
#include "MassCommonFragments.h"
#include "Engine/World.h"
#include "MassActorSubsystem.h"
#include "MassEntityQuery.h"
#include "MassRepresentationFragments.h"
#include "MassCrowdRepresentationSubsystem.h"
#include <MassStateTreeFragments.h>

void UCustomMassEntityTraitBase::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	UMassEntitySubsystem* EntitySubsystem = UWorld::GetSubsystem<UMassEntitySubsystem>(&World);
	check(EntitySubsystem);
	UMassCrowdRepresentationSubsystem* RepresentationSubsystem = World.GetSubsystem<UMassCrowdRepresentationSubsystem>();
	check(RepresentationSubsystem);

// 	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
// 	EntityQuery.AddRequirement<FMassRepresentationFragment>(EMassFragmentAccess::ReadWrite);
// 	EntityQuery.AddRequirement<FMassRepresentationLODFragment>(EMassFragmentAccess::ReadOnly);
// 	EntityQuery.AddRequirement<FMassActorFragment>(EMassFragmentAccess::ReadWrite);
// 	EntityQuery.AddConstSharedRequirement<FMassRepresentationParameters>();
// 	EntityQuery.AddSharedRequirement<FMassRepresentationSubsystemSharedFragment>(EMassFragmentAccess::ReadWrite);

// 	const FConstSharedStruct ActorFragment = EntitySubsystem->GetOrCreateConstSharedFragment(UE::StructUtils::GetStructCrc32(FConstStructView::Make(Actor)), Actor);
// 	BuildContext.AddConstSharedFragment(ActorFragment);
// 	BuildContext.AddFragment<FTransformFragment>();
// 	BuildContext.AddFragment<FMassRepresentationLODFragment>();
	BuildContext.AddFragment<FMassActorFragment>();
	//BuildContext.AddFragment<FMassStateTreeFragment>();

// 	FMassRepresentationFragment& RepresentationFragment = BuildContext.AddFragment_GetRef<FMassRepresentationFragment>();
// 	RepresentationFragment.StaticMeshDescIndex = INDEX_NONE;
// 	RepresentationFragment.HighResTemplateActorIndex = TemplateActor.Get() ? RepresentationSubsystem->FindOrAddTemplateActor(TemplateActor.Get()) : INDEX_NONE;
// 	RepresentationFragment.LowResTemplateActorIndex = INDEX_NONE;
	
// 	FMassRepresentationSubsystemSharedFragment Subsystem;
// 	Subsystem.RepresentationSubsystem = RepresentationSubsystem;
// 	uint32 SubsystemHash = UE::StructUtils::GetStructCrc32(FConstStructView::Make(Subsystem));
// 	FSharedStruct SubsystemFragment = EntitySubsystem->GetOrCreateSharedFragment<FMassRepresentationSubsystemSharedFragment>(SubsystemHash, Subsystem);
// 	BuildContext.AddSharedFragment(SubsystemFragment);
// 
// 	uint32 ParamsHash = UE::StructUtils::GetStructCrc32(FConstStructView::Make(Params));
// 	FConstSharedStruct ParamsFragment = EntitySubsystem->GetOrCreateConstSharedFragment<FMassRepresentationParameters>(ParamsHash, Params);
// 	ParamsFragment.Get<FMassRepresentationParameters>().ComputeCachedValues();
// 	BuildContext.AddConstSharedFragment(ParamsFragment);

	// @todo figure out if this chunk fragment is really needed?
	//BuildContext.AddChunkFragment<FMassVisualizationChunkFragment>();
}

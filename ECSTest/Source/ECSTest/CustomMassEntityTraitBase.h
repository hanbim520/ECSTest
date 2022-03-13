// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassActorSubsystem.h"
#include "MassRepresentationFragments.h"
#include "CustomMassEntityTraitBase.generated.h"

/**
 * 
 */
UCLASS()
class ECSTEST_API UCustomMassEntityTraitBase : public UMassEntityTraitBase
{
	GENERATED_BODY()

protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const override;

	/** Actor class of this agent when spawned on server */
	UPROPERTY(EditAnywhere, Category = "Mass|Visual")
		TSubclassOf<AActor> TemplateActor;

	/** Configuration parameters for the representation processor */
	UPROPERTY(EditAnywhere, Category = "Mass|Visual")
		FMassRepresentationParameters Params;
};

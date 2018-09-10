#pragma once

#include "Core.h"
#include "Engine.h"
#include "UTMutator.h"

#include "UTVotingMod.generated.h"

UCLASS(Meta = (ChildCanTick), Config=Game)
class AUTVotingMod : public AUTMutator
{
	GENERATED_UCLASS_BODY()

	static TArray<FString> LocalList;

	UPROPERTY(Config)
	int32 RemoveMapCount;

	bool bAlteredMapList = false;

	virtual void Tick(float DeltaSeconds) override;
};

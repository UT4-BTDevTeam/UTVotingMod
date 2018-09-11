#pragma once

#include "Core.h"
#include "Engine.h"
#include "UTMutator.h"

#include "UTVotingMod.generated.h"

UCLASS(Meta = (ChildCanTick), Config=Game)
class AUTVotingMod : public AUTMutator
{
	GENERATED_UCLASS_BODY()

	static TArray<FString> LockoutList;

	UPROPERTY(Config)
	int32 MapLockoutDuration;
	UPROPERTY(Config)
	int32 RandomSubsetSize;

	void Init_Implementation(const FString& Options) override;
	void NotifyMatchStateChange_Implementation(FName NewState) override;
};

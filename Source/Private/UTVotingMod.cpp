#include "UTVotingMod.h"

#include "UnrealTournament.h"

#define DEBUGLOG Verbose
//#define DEBUGLOG Log

AUTVotingMod::AUTVotingMod(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

TArray<FString> AUTVotingMod::LockoutList;

void AUTVotingMod::Init_Implementation(const FString& Options)
{
	MapLockoutDuration = FMath::Clamp(UGameplayStatics::GetIntOption(Options, "MapLockoutDuration", MapLockoutDuration), 0, 999);
	RandomSubsetSize = FMath::Clamp(UGameplayStatics::GetIntOption(Options, "RandomSubsetSize", RandomSubsetSize), 0, 999);

	Super::Init_Implementation(Options);
}

void AUTVotingMod::NotifyMatchStateChange_Implementation(FName NewState)
{
	if (NewState == MatchState::MapVoteHappening)
	{
		UE_LOG(LogBlueprintUserMessages, DEBUGLOG, TEXT("VotingMod: MAP VOTE HAPPENING"));

		AUTGameState* GameState = GetWorld()->GetGameState<AUTGameState>();
		if (GameState != nullptr)
		{
			TArray<AUTReplicatedMapInfo*>& VoteList = GameState->MapVoteList;

			UE_LOG(LogBlueprintUserMessages, DEBUGLOG, TEXT("VotingMod: PRE ALTER MAP LIST (%i)"), VoteList.Num());

			// 1. Lockout
			UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: CONFIG MapLockoutDuration: %i"), MapLockoutDuration);
			if (MapLockoutDuration > 0)
			{
				FString CurrentMap = UUTGameplayStatics::GetLevelName(this, false);
				UE_LOG(LogBlueprintUserMessages, DEBUGLOG, TEXT("VotingMod: CURRENT MAP '%s'"), *CurrentMap);

				LockoutList.Push(CurrentMap);
				while (LockoutList.Num() > MapLockoutDuration)
					LockoutList.RemoveAt(0);

				UE_LOG(LogBlueprintUserMessages, DEBUGLOG, TEXT("VotingMod: LOCKOUT LIST SIZE: %i"), LockoutList.Num());

				for (int32 i = 0; i < LockoutList.Num(); i++)
				{
					for (int32 j = 0; j < VoteList.Num(); j++)
					{
						if (VoteList[j]->MapPackageName == LockoutList[i])
						{
							UE_LOG(LogBlueprintUserMessages, DEBUGLOG, TEXT("VotingMod: REMOVING MAP '%s'"), *(VoteList[j]->MapPackageName));
							VoteList.RemoveAt(j);
							break;
						}
					}
				}
			}

			// 2. Subset
			UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: CONFIG RandomSubsetSize: %i"), RandomSubsetSize);
			if (RandomSubsetSize > 0)
			{
				while (VoteList.Num() > RandomSubsetSize)
					VoteList.RemoveAt(FMath::RandRange(0, VoteList.Num() - 1));
			}

			GameState->MapVoteListCount = VoteList.Num();
			UE_LOG(LogBlueprintUserMessages, DEBUGLOG, TEXT("VotingMod: POST ALTER MAP LIST (%i)"), VoteList.Num());
		}
	}

	Super::NotifyMatchStateChange_Implementation(NewState);
}

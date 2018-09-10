#include "UTVotingMod.h"

#include "UnrealTournament.h"

AUTVotingMod::AUTVotingMod(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

TArray<FString> AUTVotingMod::LocalList;

void AUTVotingMod::Tick(float DeltaSeconds)
{
	if (bAlteredMapList || RemoveMapCount == 0)
		return;

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		AUTGameMode* GameMode = Cast<AUTGameMode>(UGameplayStatics::GetGameMode(this));
		AUTGameState* GameState = World->GetGameState<AUTGameState>();
		if ( GameMode != nullptr && GameState != nullptr)
		{
			TArray<AUTReplicatedMapInfo*>& VoteList = GameState->MapVoteList;
			if (VoteList.Num() > 0)
			{
				UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: CONFIG RemoveMapCount: %i"), RemoveMapCount);
				UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: PRE ALTER MAP LIST (%i)"), VoteList.Num());

				FString CurrentMap = UUTGameplayStatics::GetLevelName(this, false);
				UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: CURRENT MAP '%s'"), *CurrentMap);

				LocalList.Push(CurrentMap);
				while (LocalList.Num() > RemoveMapCount)
					LocalList.RemoveAt(0);

				UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: LOCAL LIST SIZE: %i"), LocalList.Num());

				for (int32 i = 0; i < LocalList.Num(); i++)
				{
					for (int32 j = 0; j < VoteList.Num(); j++)
					{
						if (VoteList[j]->MapPackageName == LocalList[i])
						{
							UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: REMOVING MAP '%s'"), *(VoteList[j]->MapPackageName));
							VoteList.RemoveAt(j);
							break;
						}
					}
				}
				GameState->MapVoteListCount = VoteList.Num();

				bAlteredMapList = true;

				UE_LOG(LogBlueprintUserMessages, Log, TEXT("VotingMod: POST ALTER MAP LIST (%i)"), VoteList.Num());
			}
		}
	}
}

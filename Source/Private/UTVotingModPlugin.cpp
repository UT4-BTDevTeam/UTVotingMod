
#include "UTVotingMod.h"

#include "ModuleManager.h"
#include "ModuleInterface.h"

class FUTVotingModPlugin : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FUTVotingModPlugin, UTVotingMod )

//================================================
// Startup
//================================================

void FUTVotingModPlugin::StartupModule()
{
	UE_LOG(LogLoad, Log, TEXT("[UTVotingMod] StartupModule"));
}

//================================================
// Shutdown
//================================================

void FUTVotingModPlugin::ShutdownModule()
{
	UE_LOG(LogLoad, Log, TEXT("[UTVotingMod] ShutdownModule"));
}

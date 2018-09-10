
namespace UnrealBuildTool.Rules
{
	public class UTVotingMod : ModuleRules
	{
		public UTVotingMod(TargetInfo Target)
        {
            PrivateIncludePaths.Add("UTVotingMod/Private");

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
                    "Engine",
                    "UnrealTournament",
				}
			);
		}
	}
}
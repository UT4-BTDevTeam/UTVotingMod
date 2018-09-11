# UTVotingMod
UT4 serverside plugin to improve mapvote rotation.

### Map lockout
If enabled, disables each voted map for the desired amount of subsequent matches. For example with a value of 5, when DM-Cheops is voted, it will not appear in the maplist anymore until 5 more maps are played.

### Random subset
If enabled, the mod will automatically trim the maplist down to the desired size, picking random maps in the list.
This is similar to when the game selects 3 random maps at 10 seconds left, except here it happens right from the start.
Can be combined with map lockout.

## Installing

### Plugin
Paste the repository folder in
```
UTServer/UnrealTournament/Plugins/
```
Make sure the result path looks like this :
```
UTServer/UnrealTournament/Plugins/UTVotingMod/Binaries/Linux/libUE4Server-UTVotingMod-Linux-Shipping.so
```

### Enable mutator
**(recommended)** Use the blueprint loader, so clients will be able to see the mutator in "Custom" screen after downloading it once. You must install `MutAddVotingMod-WindowsNoEditor.pak` like any other blueprint mutator (redirect reference etc.) !
[Get it from UTCC](https://utcc.unrealpugs.com/mutator/651-Mapvote-Rotation-(plugin)).
```
Mutator=MutAddVotingMod
```
**(or)** Load the native mutator directly - no redirect is required as nothing is sent to clients. Players will never see the mutator in "Custom" screen.
```
Mutator=UTVotingMod.UTVotingMod
```

### Configuration
in rulesets :
```
?MapLockoutDuration=5?RandomSubsetSize=9
```
in Game.ini
```ini
[/Script/UTVotingMod.UTVotingMod]
MapLockoutDuration=5
RandomSubsetSize=9
```
Use a value of 0 to disable either feature.

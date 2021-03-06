# UTVotingMod
UT4 serverside plugin to improve mapvote rotation.

### Map lockout
If enabled, disables each voted map for an amount of subsequent matches. For example with a value of 3, when DM-Cheops is voted, it will not appear in the maplist anymore until 3 more maps are played.

### Random subset
If enabled, only a subset of the full map list appears in the voting screen. The subset is selected randomly every match.
This is similar to when the game selects 3 random maps at 10 seconds left, except here it happens right from the start.
Can be combined with map lockout.

## Installing

### Plugin
Download repository ZIP, extract, and paste the entire folder into :
```
UTServer/UnrealTournament/Plugins/
```
Make sure the result path looks like this :
```
UTServer/UnrealTournament/Plugins/UTVotingMod-master/Binaries/Linux/libUE4Server-UTVotingMod-Linux-Shipping.so
```

### Enable mutator
**(recommended)** Use the blueprint loader, so players will be able to see the mutator in "Custom" screen after downloading it once. You must install [MutAddVotingMod-WindowsNoEditor.pak](https://utcc.unrealpugs.com/mutator/651-Mapvote-Rotation-(plugin)) like any other blueprint mutator (redirect reference etc.) !
```
Mutator=MutAddVotingMod
```
**(or)** Load the native mutator directly - no redirect is required as nothing is sent to clients. Players will never see the mutator in "Custom" screen.
```
Mutator=UTVotingMod.UTVotingMod
```

### Configuration
Via ruleset options :
```
?MapLockoutDuration=3?RandomSubsetSize=9
```
Via Game.ini :
```ini
[/Script/UTVotingMod.UTVotingMod]
MapLockoutDuration=3
RandomSubsetSize=9
```
Options have priority over ini config.
Use a value of 0 to disable either feature.

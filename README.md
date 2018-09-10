# UTVotingMod
UT4 serverside plugin to improve mapvote rotation.

Currently this mutator disables each voted map for a configurable amount of subsequent matches. For example with a value of 3, when DM-Cheops is voted, it will not appear in the maplist anymore until 3 more maps are played. With a value of 1, only the current map will always be stripped from the list.

More options may come in the future for configuring different rotation systems, depending on the demand.

### Install
Paste the repository in
```
UTServer/UnrealTournament/Plugins/
```
Make sure the result path looks like this :
```
UTServer/UnrealTournament/Plugins/UTVotingMod/Binaries/Linux/libUE4Server-UTVotingMod-Linux-Shipping.so
```
You can remove the binaries folder that does not match your architecture.

### Mutator
```
UTVotingMod.UTVotingMod
```

### Game.ini
```ini
[/Script/UTVotingMod.UTVotingMod]
RemoveMapCount=10
```

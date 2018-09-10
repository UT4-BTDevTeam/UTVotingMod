# UTVotingMod
UT4 serverside plugin to improve mapvote rotation

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

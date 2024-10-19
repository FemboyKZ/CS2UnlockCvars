# CS2UnlockCvars

CS2UnlockCvars is a plugin made by stripping [CS2Fixes](https://github.com/Source2ZE/CS2Fixes/) of most of its features and only leaving the cvar unlocking part intact.

All credit goes to CS2Fixes

The plugin unlocks all dev only and hidden convars and commands.

## Installation

- Install [Metamod](https://www.sourcemm.net/downloads.php?branch=dev)
- Download the [latest release package](https://github.com/FemboyKZ/CS2UnlockCvars/releases/latest) for your OS
- Extract the package contents into `game/csgo` on your server

## Compilation

### Requirements

- [Metamod:Source](https://www.sourcemm.net/downloads.php/?branch=master) (build 1219 or higher)
- [AMBuild](https://wiki.alliedmods.net/Ambuild)

### Instructions

```bash
git clone https://github.com/FemboyKZ/CS2UnlockCvars/ && cd CS2UnlockCvars
git submodule update --init --recursive

export MMSOURCE112=/path/to/metamod/
export HL2SDKCS2=/path/to/sdk/submodule

mkdir build && cd build
python3 ../configure.py --enable-optimize --symbol-files --sdks cs2
ambuild
```

Copy the contents of package/ to your server's csgo/ directory.

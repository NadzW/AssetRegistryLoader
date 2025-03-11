# AssetRegistryLoader
A UE4SS mod to load additional asset registries from mod paks. Originally created for Tokyo Xtreme Racing.

---

## Build requirements (Same as [UE4SS](https://github.com/UE4SS-RE/RE-UE4SS))
* A computer running Windows.
* A version of MSVC that supports C++23:
  * MSVC toolset version >= 14.39.0
  * MSVC version >= 19.39.0
  * Visual Studio version >= 17.9
  * More compilers will hopefully be supported in the future.
* Rust toolchain >= 1.73.0
* xmake >= 2.9.3


## Setup Instructions
1. Clone the repository.
2. Execute this command: `git submodule update --init --recursive` Make sure your Github account is linked to your Epic Games account for UE source access.
***Do not use the `--remote` option because that will force third-party dependencies to update to the latest commit, and that can break things. 
You will need your github account to be linked to an Epic games account to pull the Unreal pseudo code submodule.***
3. Execute this command: `xmake f -m "Game__Shipping__Win64"`

## Build Instructions
Whenever you need to rebuild the mod, simply execute `xmake` in the project root. This will build the mod into a `AssetRegistryLoader.dll` in
`AssetRegistryLoader\Binaries\Game__Shipping__Win64\AssetRegistryLoader\`. 
Follow the [UE4SS guide on how to install a c++ mod](https://docs.ue4ss.com/dev/guides/installing-a-c++-mod.html) to learn how to load and test the mod.

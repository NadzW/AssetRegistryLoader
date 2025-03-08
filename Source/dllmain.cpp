#include <Mod/CppUserModBase.hpp>
#include <DynamicOutput/DynamicOutput.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UObject.hpp>
#include <Helpers/String.hpp>
#include <SigScanner/SinglePassSigScanner.hpp>
#include <UE4SSProgram.hpp>
#include <Unreal/Signatures.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <Unreal/FString.hpp>

using namespace RC;
using namespace RC::Unreal;

struct IFileManager
{
    virtual bool FileExists(const wchar_t* FileName) = 0; 
};

struct FAssetRegistryState
{
};

class FAssetRegistryLoadOptions
{
    FAssetRegistryLoadOptions();

	bool bLoadDependencies = true;
	bool bLoadPackageData = true;
	int32 ParallelWorkers = 0;
};

Function<IFileManager*()> GetIFileManager;
Function<bool(std::string* InPath, FAssetRegistryLoadOptions& InOptions, FAssetRegistryState& OutState)> LoadFromDisk;
Function<void*(FAssetRegistryState& InState)> AppendState;

void ScanForFunctions()
{
    const SignatureContainer Get_I_FileManager
    {
        {{"48 83 EC 28 8B 0D ?? ?? ?? ?? 65 48 8B 04 25 58 00 00 00 BA EC 0E 00 00 48 8B 04 C8 8B 04 02 39 05 ?? ?? ?? ?? 7F 0C 48 8D 05 ?? ?? ?? ?? 48 83 C4 28 C3 48 8D 0D"}},
        [&](const SignatureContainer &self) {
            GetIFileManager.assign_address(self.get_match_address());
            return true;
        },
        [](SignatureContainer &self) {},
    };

    const SignatureContainer Load_From_Disk
    {
        {{"48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 56 48 81 EC 10 01 00 00 49 8B F1 49 8B E8 4C 8B F2 48 8B D9 E8 ?? ?? ?? ??"}},
        [&](const SignatureContainer &self) {
            LoadFromDisk.assign_address(self.get_match_address());
            return true;
        },
        [](SignatureContainer &self) {},
    };

    const SignatureContainer Append_State
    {
        {{"48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 45 8B D1 48 8D 81 ?? ?? ?? ?? 49 8B D8 44 89 54 24 28 4D 8D 88 ?? ?? ?? ?? 48 89 44 24 20 48 8B FA 49 81 C0 90 01 00 00 48 8B D3 48 8B F1 E8 ?? ?? ?? ??"}},
        [&](const SignatureContainer &self) {
            AppendState.assign_address(self.get_match_address());
            return true;
        },
        [](SignatureContainer &self) {},
    };

    std::vector<SignatureContainer> signature_containers;
    signature_containers.push_back(Get_I_FileManager);
    signature_containers.push_back(Load_From_Disk);
    signature_containers.push_back(Append_State);


    SinglePassScanner::SignatureContainerMap signature_containers_map;
    signature_containers_map.emplace(ScanTarget::MainExe, signature_containers);
    SinglePassScanner::start_scan(signature_containers_map);
}


class AssetRegistryLoader : public RC::CppUserModBase
{
public:

    
    AssetRegistryLoader() : CppUserModBase()
    {
        ModName = STR("AssetRegistryLoader");
        ModVersion = STR("0.0.2");
        ModDescription = STR("Loads asset registries from all pakchunks. Made for TokyoXtremeRacer UE5.4.4");
        ModAuthors = STR("Nadz");
    }

    ~AssetRegistryLoader() override
    {
    }

    auto on_update() -> void override
    {
    }

    auto on_unreal_init() -> void override
    {
        ScanForFunctions();

    }

};

#define ASSET_REGISTRY_LOADER_API __declspec(dllexport)
extern "C"
{
    ASSET_REGISTRY_LOADER_API RC::CppUserModBase* start_mod()
    {
        return new AssetRegistryLoader();
    }

    ASSET_REGISTRY_LOADER_API void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}

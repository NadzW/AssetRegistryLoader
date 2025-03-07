#include <Mod/CppUserModBase.hpp>
#include <DynamicOutput/DynamicOutput.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UObject.hpp>

using namespace RC;
using namespace RC::Unreal;

class AssetRegistryLoader : public RC::CppUserModBase
{
public:

    auto GetIFileManagerAOB = "48 83 EC 28 8B 0D ?? ?? ?? ?? 65 48 8B 04 25 58 00 00 00 BA EC 0E 00 00 48 8B 04 C8 8B 04 02 39 05 ?? ?? ?? ?? 7F 0C 48 8D 05 ?? ?? ?? ?? 48 83 C4 28 C3 48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 3D ?? ?? ?? ?? FF 75 DF 48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? EB C5 "
    auto LoadFromDiskAOB = "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 56 48 81 EC 10 01 00 00 49 8B F1 49 8B E8 4C 8B F2 48 8B D9 E8 ?? ?? ?? ?? 45 33 C0 48 8B D3 48 8B C8 4C 8B 10 41 FF 52 ?? 48 8B F8 48 85 C0 0F 84 19 01 00 00 0F 57 C0 48 C7 44 24 40 00 00 00 00 F3 0F 7F 44 24 30 48 8B 00 48 8B CF FF 50 ?? 4C 8B 44 24 38 4C 8B C8 49 3B C0 7E 27 48 8B 4C 24 40 4D 2B C8 49 8B D0 4D 03 C1 48 2B CA 4C 89 44 24 38 4C 3B C9 76 5D 48 8D 4C 24 30 E8 ?? ?? ?? ?? EB 4C 4D 85 C9 0F 88 E4 00 00 00 4D 3B C8 7D 43 49 8B D8 49 2B D9 74 3B 48 8B 4C 24 30 49 8B C0 49 03 C9 48 2B C3 49 2B C1 74 11 48 8D 14 19 4C 8B C0 E8 ?? ?? ?? ?? 4C 8B 44 24 38 4C 2B C3 48 8D 4C 24 30 4C 89 44 24 38 E8 ?? ?? ?? ?? 4C 8B 44 24 38 48 8B 07 48 8B CF 48 8B 54 24 30 FF 90 ?? ?? ?? ?? 4C 8B 44 24 38 48 8D 4C 24 50 48 8B 54 24 30 45 33 C9 48 C7 44 24 48 00 00 00 00 48 8B 44 24 48 48 89 44 24 20 E8 ?? ?? ?? ?? 4C 8B CE 48 8D 54 24 50 4D 8B C6 48 8B CD E8 ?? ?? ?? ?? 48 8D 4C 24 50 0F B6 D8 E8 ?? ?? ?? ?? 48 8B 4C 24 30 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 8B 07 BA 01 00 00 00 48 8B CF FF 10 EB 02 32 DB 4C 8D 9C 24 10 01 00 00 0F B6 C3 49 8B 5B ?? 49 8B 6B ?? 49 8B 73 ?? 49 8B 7B ?? 49 8B E3 41 5E C3 "
    auto AppendStateAOB = "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 45 8B D1 48 8D 81 ?? ?? ?? ?? 49 8B D8 44 89 54 24 28 4D 8D 88 ?? ?? ?? ?? 48 89 44 24 20 48 8B FA 49 81 C0 90 01 00 00 48 8B D3 48 8B F1 E8 ?? ?? ?? ?? 4C 8B C3 48 8B D7 48 8B CE 48 8B 5C 24 40 48 8B 74 24 48 48 83 C4 30 5F E9 41 28 00 00 CC 48 89 5C 24 18 55 56 57 41 56 41 57 48 8D 6C 24 F0 48 81 EC 10 01 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 00 45 33 FF C6 44 24 50 00 4C 8B F1 4C 89 7C 24 58 48 81 C1 F8 08 00 00 4C 89 7C 24 60 4C 89 7C 24 68 48 8B F2 4C 89 7C 24 70 4C 89 7C 24 78 4C 89 7D 80 4C 89 7D 88 4C 89 7D 90 4C 89 7D 98 4C 89 7D A0 44 88 7D A8 FF 15 ?? ?? ?? ?? 49 8D 86 ?? ?? ?? ?? C7 44 24 28 02 00 00 00 4C 8D 8E ?? ?? ?? ?? 48 89 44 24 20 4C 8D 86 ?? ?? ?? ?? 48 8B D6 49 8D 4E ?? E8 ?? ?? ?? ?? 4C 8B C6 48 8D 54 24 40 49 8D 4E ?? E8 ?? ?? ?? ?? 49 8D 8E ?? ?? ?? ?? FF 15 ?? ?? ?? ?? 41 B1 01 4C 89 7C 24 30 4C 8D 44 24 30 4C 89 7C 24 38 48 8D 55 B0 4C 89 7D B0 48 8B CE 4C 89 7D B8 4C 89 7D D0 44 89 7D D8 C7 45 DC 80 00 00 00 C7 45 E0 FF FF FF FF 44 89 7D E4 4C 89 7D F0 44 89 7D F8 E8 ?? ?? ?? ?? 48 8B 4D F0 44 89 7D F8 48 85 C9 74 05 E8 ?? ?? ?? ?? 44 89 7D B8 44 39 7D BC 74 0B 33 D2 48 8D 4D B0 E8 ?? ?? ?? ?? 81 7D DC 80 00 00 00 C7 45 E0 FF FF FF FF 44 89 7D E4 44 89 7D D8 76 12 33 D2 C7 45 DC 80 00 00 00 48 8D 4D C0 E8 ?? ?? ?? ?? 48 8B 4D D0 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 8B 4D B0 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 8B 7C 24 30 48 63 44 24 38 48 6B F0 68 48 03 F7 48 3B FE 74 46 0F 1F 80 00 00 00 00 48 63 5C 24 70 8D 43 ?? 89 44 24 70 3B 44 24 74 76 0C 8B D3 48 8D 4C 24 68 E8 ?? ?? ?? ?? 48 6B DB 70 48 8B D7 48 03 5C 24 68 48 8B CB E8 ?? ?? ?? ?? 48 83 C7 68 44 89 7B ?? 48 3B FE 75 C1 49 8D 4E ?? 48 8D 54 24 40 E8 ?? ?? ?? ?? 8B 74 24 38 85 F6 74 67 48 8B 7C 24 30 48 83 C7 48 66 90 48 8B 4F ?? 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 8B 1F 48 85 DB 74 34 B8 FF FF FF FF F0 0F C1 43 ?? 83 F8 01 75 25 48 8B 03 48 8B CB FF 10 B8 FF FF FF FF F0 0F C1 43 ?? 83 F8 01 75 0E 48 8B 03 BA 01 00 00 00 48 8B CB FF 50 ?? 48 8D 4F ?? E8 ?? ?? ?? ?? 48 83 C7 68 83 EE 01 75 A4 48 8B 4C 24 30 48 85 C9 74 05 E8 ?? ?? ?? ?? 8B 7D A0 48 8B 5D 98 85 FF 74 1A 48 8B 0B 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 83 C3 10 83 EF 01 75 EA 48 8B 5D 98 48 85 DB 74 08 48 8B CB E8 ?? ?? ?? ?? 8B 7D 90 48 8B 5D 88 85 FF 74 1A 48 8B 0B 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 83 C3 10 83 EF 01 75 EA 48 8B 5D 88 48 85 DB 74 08 48 8B CB E8 ?? ?? ?? ?? 48 8B 4C 24 78 48 85 C9 74 05 E8 ?? ?? ?? ?? 8B 7C 24 70 48 8B 5C 24 68 85 FF 74 1B 0F 1F 44 00 00 48 8B CB E8 ?? ?? ?? ?? 48 83 C3 70 83 EF 01 75 EF 48 8B 5C 24 68 48 85 DB 74 08 48 8B CB E8 ?? ?? ?? ?? 8B 7C 24 60 48 8B 5C 24 58 85 FF 74 1B 48 8B 0B 48 85 C9 74 05 E8 ?? ?? ?? ?? 48 83 C3 18 83 EF 01 75 EA 48 8B 5C 24 58 48 85 DB 74 08 48 8B CB E8 ?? ?? ?? ?? 48 8B 4D 00 48 33 CC E8 ?? ?? ?? ?? 48 8B 9C 24 50 01 00 00 48 81 C4 10 01 00 00 41 5F 41 5E 5F 5E 5D C3 "

    AssetRegistryLoader() : CppUserModBase()
    {
        ModName = STR("AssetRegistryLoader");
        ModVersion = STR("0.0.2");
        ModDescription = STR("Loads asset registries from all pakchunks. Made for TokyoXtremeRacer UE5.4.4");
        ModAuthors = STR("Nadz");
        
        auto func = reinterpret_cast<>(sigscan::get().scan_string(""));
    }

    ~AssetRegistryLoader() override
    {
    }

    auto on_update() -> void override
    {
    }

    auto on_unreal_init() -> void override
    {

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

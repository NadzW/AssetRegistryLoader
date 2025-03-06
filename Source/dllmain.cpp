#include <Mod/CppUserModBase.hpp>
#include <DynamicOutput/DynamicOutput.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UObject.hpp>

using namespace RC;
using namespace RC::Unreal;

class AssetRegistryLoader : public RC::CppUserModBase
{
public:
    AssetRegistryLoader() : CppUserModBase()
    {
        ModName = STR("AssetRegistryLoader");
        ModVersion = STR("0.0.1");
        ModDescription = STR("This is my awesome mod");
        ModAuthors = STR("Nadz");
        
        Output::send<LogLevel::Verbose>(STR("AssetRegistryLoader says hello\n"));
    }

    ~AssetRegistryLoader() override
    {
    }

    auto on_update() -> void override
    {
    }

    auto on_unreal_init() -> void override
    {
        auto Object = UObjectGlobals::StaticFindObject<UObject*>(nullptr, nullptr, STR("/Script/CoreUObject.Object"));
        Output::send<LogLevel::Verbose>(STR("Object Name: {}\n"), Object->GetFullName());
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

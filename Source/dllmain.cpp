#include <stdio.h>
#include <Mod/CppUserModBase.hpp>

class AssetRegistryLoader : public RC::CppUserModBase
{
public:
    AssetRegistryLoader() : CppUserModBase()
    {
        ModName = STR("AssetRegistryLoader");
        ModVersion = STR("0.0.1");
        ModDescription = STR("This is my awesome mod");
        ModAuthors = STR("Nadz");
        
        printf("AssetRegistryLoader says hello\n");
    }

    ~AssetRegistryLoader() override
    {
    }

    auto on_update() -> void override
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

includes("RE-UE4SS")
set_languages("c++23")

local projectName = "AssetRegistryLoader"

target(projectName)
    add_rules("ue4ss.mod")
    add_includedirs(".")
    add_files("./source/dllmain.cpp")
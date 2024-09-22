// This file is part of the Blueprint accessible GLTF data library.
// 
// Copyright (c) 2024 - Rohan Singh
//
// This software is licensed under the MIT License.
// See the LICENSE file in the project root for more information.

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#ifdef _WIN32
  // Windows is typically little-endian
#define TINYGLTF_LITTLE_ENDIAN
#else
  // Other platforms may have different endianness, use existing __BYTE_ORDER__ macro
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define TINYGLTF_LITTLE_ENDIAN
#else
#define TINYGLTF_BIG_ENDIAN
#endif
#endif
// #define TINYGLTF_NOEXCEPTION // optional. disable exception handling.

#include "GltfLibrary.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "tiny_gltf.h"



void UGltfLibrary::LoadGLTF(const FString& FilePath)
{
    // Create a TinyGLTF loader object
    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string err;
    std::string warn;

    // Convert the Unreal FString to a standard string for TinyGLTF
    std::string InputFile = TCHAR_TO_UTF8(*FilePath);

    // Check if the file is binary (.glb) or JSON (.gltf)
    bool isBinary = FilePath.EndsWith(TEXT(".glb"));

    bool result = false;
    if (isBinary)
    {
        result = loader.LoadBinaryFromFile(&model, &err, &warn, InputFile);
    }
    else
    {
        result = loader.LoadASCIIFromFile(&model, &err, &warn, InputFile);
    }

    if (!warn.empty())
    {
        UE_LOG(LogTemp, Warning, TEXT("TinyGLTF Warning: %s"), *FString(warn.c_str()));
    }

    if (!err.empty())
    {
        UE_LOG(LogTemp, Error, TEXT("TinyGLTF Error: %s"), *FString(err.c_str()));
    }

    if (!result)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load glTF file: %s"), *FilePath);
        return;
    }

    // Print basic data from the glTF model
    UE_LOG(LogTemp, Log, TEXT("glTF File Loaded: %s"), *FilePath);
    UE_LOG(LogTemp, Log, TEXT("Number of scenes: %d"), model.scenes.size());
    UE_LOG(LogTemp, Log, TEXT("Number of nodes: %d"), model.nodes.size());
    UE_LOG(LogTemp, Log, TEXT("Number of meshes: %d"), model.meshes.size());
    UE_LOG(LogTemp, Log, TEXT("Number of materials: %d"), model.materials.size());

    // Print node names and mesh names if available
    for (size_t i = 0; i < model.nodes.size(); i++)
    {
        const auto& node = model.nodes[i];
        FString nodeName = node.name.empty() ? TEXT("Unnamed Node") : FString(node.name.c_str());
        UE_LOG(LogTemp, Log, TEXT("Node %d: %s"), i, *nodeName);
    }

    for (size_t i = 0; i < model.meshes.size(); i++)
    {
        const auto& mesh = model.meshes[i];
        FString meshName = mesh.name.empty() ? TEXT("Unnamed Mesh") : FString(mesh.name.c_str());
        UE_LOG(LogTemp, Log, TEXT("Mesh %d: %s"), i, *meshName);
    }
}
// Fill out your copyright notice in the Description page of Project Settings.

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
//#include "ProceduralMeshComponent.h"


// Function to load and print glTF data
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
        //CreateProceduralMesh(mesh, model);
    }
}

//// Create a procedural mesh from glTF mesh data
//void UGltfLibrary::CreateProceduralMesh(const tinygltf::Mesh& mesh, tinygltf::Model model)
//{
//    for (const tinygltf::Primitive& primitive : mesh.primitives) {
//        // Retrieve vertex positions
//        const tinygltf::Accessor& posAccessor = model.accessors[primitive.attributes.find("POSITION")->second];
//        const tinygltf::BufferView& posView = model.bufferViews[posAccessor.bufferView];
//        const tinygltf::Buffer& posBuffer = model.buffers[posView.buffer];
//
//        // Retrieve vertex normals (if available)
//        const tinygltf::Accessor* normalAccessor = nullptr;
//        const tinygltf::BufferView* normalView = nullptr;
//        const tinygltf::Buffer* normalBuffer = nullptr;
//
//        auto normalIt = primitive.attributes.find("NORMAL");
//        if (normalIt != primitive.attributes.end()) {
//            normalAccessor = &model.accessors[normalIt->second];
//            normalView = &model.bufferViews[normalAccessor->bufferView];
//            normalBuffer = &model.buffers[normalView->buffer];
//        }
//
//        // Retrieve index data
//        const tinygltf::Accessor& indexAccessor = model.accessors[primitive.indices];
//        const tinygltf::BufferView& indexView = model.bufferViews[indexAccessor.bufferView];
//        const tinygltf::Buffer& indexBuffer = model.buffers[indexView.buffer];
//
//        // Create arrays to hold Unreal's vertex and index data
//        TArray<FVector> Vertices;
//        TArray<int32> Triangles;
//
//        // Populate vertices
//        for (size_t i = 0; i < posAccessor.count; i++) {
//            float x = *((float*)(&posBuffer.data[posView.byteOffset + i * 12]));
//            float y = *((float*)(&posBuffer.data[posView.byteOffset + i * 12 + 4]));
//            float z = *((float*)(&posBuffer.data[posView.byteOffset + i * 12 + 8]));
//            Vertices.Add(FVector(x, y, z));
//        }
//
//        // Populate triangles
//        for (size_t i = 0; i < indexAccessor.count; i++) {
//            int32 index = *((unsigned short*)(&indexBuffer.data[indexView.byteOffset + i * 2])); // Assuming 16-bit indices
//            Triangles.Add(index);
//        }
//
//        //// Create the ProceduralMeshComponent dynamically and attach it to the actor
//        //UProceduralMeshComponent* ProcMesh = NewObject<UProceduralMeshComponent>(GetOwner());
//        //ProcMesh->RegisterComponent();
//        //ProcMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
//
//        //// Attach the procedural mesh to the actor
//        //ProcMesh->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
//    }
//}
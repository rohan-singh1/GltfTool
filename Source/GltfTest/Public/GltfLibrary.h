// This file is part of the Blueprint accessible GLTF data library.
// 
// Copyright (c) 2024 - Rohan Singh
//
// This software is licensed under the MIT License.
// See the LICENSE file in the project root for more information.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GltfLibrary.generated.h"


USTRUCT(BlueprintType)
struct FGltfMetadata
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    FString FileName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    FString FilePath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 SceneCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 NodeCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 MeshCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 MaterialCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 BufferCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 BufferViewCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 AccessorCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 TextureCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 ImageCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 CameraCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Metadata")
    int32 AnimationCount;
};

USTRUCT(BlueprintType)
struct FGltfAsset
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Asset")
    FString Version;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Asset")
    FString Generator;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GLTF|Asset")
    FString MinVersion;

    FGltfAsset()
        : Version(TEXT("2.0"))
    {}
};

/**
 * 
 */
UCLASS()
class GLTFTEST_API UGltfLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "GLTF")
	static void LoadGLTF(const FString& FilePath);
};

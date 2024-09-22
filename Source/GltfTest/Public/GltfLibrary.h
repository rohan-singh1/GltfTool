//
// Blueprint accessible GLTF data library
//
//
// The MIT License (MIT)
//
// Copyright (c) 2024 - Rohan Singh
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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

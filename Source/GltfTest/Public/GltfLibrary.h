// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GltfLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GLTFTEST_API UGltfLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "GLTF")
	static void LoadGLTF(const FString& FilePath);
	
	//static void CreateProceduralMesh(const tinygltf::Mesh& mesh, tinygltf::Model model);
};

// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#include "GeoreferenceBlueprintFunctions.h"
#include "CoreMinimal.h"
#include "GeoreferenceFunctions.h"

UGeoreferenceBlueprintFunctions::UGeoreferenceBlueprintFunctions(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {}
FVector
UGeoreferenceBlueprintFunctions::convert_EXAMPLE(const FVector& vector) {
  glm::dvec3 dVector; // create from vector
  glm::dvec3 dResult = UGeoreferenceFunctions::convert_EXAMPLE(dVector);
  FVector result; // create from dResult
  return result;
}

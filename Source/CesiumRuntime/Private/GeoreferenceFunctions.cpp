// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#include "GeoreferenceFunctions.h"
#include "CoreMinimal.h"

UGeoreferenceFunctions::UGeoreferenceFunctions(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {}

glm::dvec3 UGeoreferenceFunctions::convert_EXAMPLE(const glm::dvec3& vector) {
  glm::dvec3 result(0, 0, 0);
  // convert vector, with this->_ellipsoid....
  return result;
}
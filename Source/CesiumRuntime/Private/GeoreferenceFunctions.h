// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CoreMinimal.h"
#include <glm/glm.hpp>
#include "GeoreferenceFunctions.generated.h"

UCLASS()
class UGeoreferenceFunctions : public UObject {
  GENERATED_UCLASS_BODY()

  static glm::dvec3 convert_EXAMPLE(const glm::dvec3& vector);
};
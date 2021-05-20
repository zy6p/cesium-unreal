// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CoreMinimal.h"
#include "GeoreferenceBlueprintFunctions.generated.h"

UCLASS()
class UGeoreferenceBlueprintFunctions : public UObject {
  GENERATED_UCLASS_BODY()

  UFUNCTION(BlueprintCallable, Category = "Cesium")
  static FVector convert_EXAMPLE(const FVector& vector);
};
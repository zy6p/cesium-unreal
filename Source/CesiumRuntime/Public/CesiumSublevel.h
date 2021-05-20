// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CesiumSublevel.generated.h"

/*
 * Sublevels can be georeferenced to the globe by filling out this struct.
 */
USTRUCT()
struct FCesiumSubLevel {
  GENERATED_BODY()

  /**
   * The plain name of the sub level, without any prefixes.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString LevelName;

  /**
   * The WGS84 longitude in degrees of where this level should sit on the
   * globe.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  double LevelLongitude = 0.0;

  /**
   * The WGS84 latitude in degrees of where this level should sit on the globe.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  double LevelLatitude = 0.0;

  /**
   * The height in meters above the WGS84 globe this level should sit.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  double LevelHeight = 0.0;

  /**
   * How far in meters from the sublevel local origin the camera needs to be to
   * load the level.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  double LoadRadius = 0.0;

  /**
   * Whether or not this level is currently loaded. Not relevant in the editor.
   */
  bool CurrentlyLoaded = false;
};

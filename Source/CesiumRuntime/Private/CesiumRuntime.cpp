// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#include "CesiumRuntime.h"
#include "Cesium3DTiles/registerAllTileContentTypes.h"
#include "SpdlogUnrealLoggerSink.h"
#include "UnrealEd.h"
#include <spdlog/spdlog.h>

#include "CesiumGeoreferenceComponent.h"
#include "GeoreferenceVisualizer.h"

#include "CesiumGltfComponent.h"
#include "CesiumGltfPrimitiveComponent.h"
#include "GltfBoundingBoxVisualizer.h"

#define LOCTEXT_NAMESPACE "FCesiumRuntimeModule"

DEFINE_LOG_CATEGORY(LogCesium);

void FCesiumRuntimeModule::StartupModule() {
  Cesium3DTiles::registerAllTileContentTypes();

  std::shared_ptr<spdlog::logger> pLogger = spdlog::default_logger();
  pLogger->sinks() = {std::make_shared<SpdlogUnrealLoggerSink>()};

  if (GUnrealEd) {
    TSharedPtr<FComponentVisualizer> georeferenceVisualizer =
        MakeShareable(new FGeoreferenceVisualizer());
    GUnrealEd->RegisterComponentVisualizer(
        UCesiumGeoreferenceComponent::StaticClass()->GetFName(),
        georeferenceVisualizer);
    georeferenceVisualizer->OnRegister();

    TSharedPtr<FComponentVisualizer> gltfBoundingBoxVisualizer =
        MakeShareable(new FGltfBoundingBoxVisualizer());
    GUnrealEd->RegisterComponentVisualizer(
        UCesiumGltfPrimitiveComponent::StaticClass()->GetFName(),
        gltfBoundingBoxVisualizer);
    gltfBoundingBoxVisualizer->OnRegister();
  }
}

void FCesiumRuntimeModule::ShutdownModule() {
  if (GUnrealEd) {
    GUnrealEd->UnregisterComponentVisualizer(
        UCesiumGeoreferenceComponent::StaticClass()->GetFName());
  }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCesiumRuntimeModule, CesiumRuntime)
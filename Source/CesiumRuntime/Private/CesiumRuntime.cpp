// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#include "CesiumRuntime.h"
#include "Cesium3DTiles/registerAllTileContentTypes.h"
#include "SpdlogUnrealLoggerSink.h"
#include <spdlog/spdlog.h>
#include "UnrealEd.h"
#include "CesiumGeoreferenceComponent.h"
#include "GeoreferenceVisualizer.h"

#define LOCTEXT_NAMESPACE "FCesiumRuntimeModule"

DEFINE_LOG_CATEGORY(LogCesium);

void FCesiumRuntimeModule::StartupModule() {
  Cesium3DTiles::registerAllTileContentTypes();

  std::shared_ptr<spdlog::logger> pLogger = spdlog::default_logger();
  pLogger->sinks() = {std::make_shared<SpdlogUnrealLoggerSink>()};

	if (GUnrealEd)
	{
		TSharedPtr<FComponentVisualizer> visualizer = MakeShareable(new FGeoreferenceVisualizer());
		GUnrealEd->RegisterComponentVisualizer(UCesiumGeoreferenceComponent::StaticClass()->GetFName(), visualizer);
		visualizer->OnRegister();
	}
}

void FCesiumRuntimeModule::ShutdownModule() {
	if (GUnrealEd)
	{
		GUnrealEd->UnregisterComponentVisualizer(UCesiumGeoreferenceComponent::StaticClass()->GetFName());
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCesiumRuntimeModule, CesiumRuntime)
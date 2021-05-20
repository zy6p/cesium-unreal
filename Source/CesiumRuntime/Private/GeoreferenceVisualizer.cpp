#include "GeoreferenceVisualizer.h"
#include "CesiumGeoreferenceComponent.h"
#include "SceneManagement.h"

void FGeoreferenceVisualizer::DrawVisualization(
    const UActorComponent* Component,
    const FSceneView* View,
    FPrimitiveDrawInterface* PDI) {
  const UCesiumGeoreferenceComponent* cesiumGeoreferenceComponent =
      Cast<const UCesiumGeoreferenceComponent>(Component);

  FVector axisLoc(1, 0, 0);
  FRotator axisRot(0, 0, 0);
  float scale = 100000.0f;
  int8 depthPriority = SDPG_Foreground;
  float thickness = 100.0f;
  // DrawCoordinateSystem(PDI, axisLoc, axisRot, scale, depthPriority,
  // thickness);

  glm::dvec3 ecef(
      cesiumGeoreferenceComponent->ECEF_X,
      cesiumGeoreferenceComponent->ECEF_Y,
      cesiumGeoreferenceComponent->ECEF_Z);
  glm::dvec3 ueCenter =
      cesiumGeoreferenceComponent->Georeference->TransformEcefToUe(ecef);
  FVector fUeCenter(ueCenter.x, ueCenter.y, ueCenter.y);

  PDI->DrawLine(
      fUeCenter,
      axisLoc + FVector(scale, 0.0f, 0.0f),
      FLinearColor::Red,
      depthPriority,
      thickness);
  PDI->DrawLine(
      fUeCenter,
      axisLoc + FVector(0.0f, scale, 0.0f),
      FLinearColor::Green,
      depthPriority,
      thickness);
  PDI->DrawLine(
      fUeCenter,
      axisLoc + FVector(0.0f, 0.0f, scale),
      FLinearColor::Blue,
      depthPriority,
      thickness);
}
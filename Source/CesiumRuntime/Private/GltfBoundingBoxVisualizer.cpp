#include "GltfBoundingBoxVisualizer.h"
#include "CesiumGltfComponent.h"
#include "CesiumGltfPrimitiveComponent.h"
#include "SceneManagement.h"

void FGltfBoundingBoxVisualizer::DrawVisualization(
    const UActorComponent* Component,
    const FSceneView* View,
    FPrimitiveDrawInterface* PDI) {
  const FVector axisLoc(1, 0, 0);
  FRotator axisRot(0, 0, 0);
  float scale = 100000.0f;
  int8 depthPriority = SDPG_Foreground;
  float thickness = 100.0f;
  const FLinearColor& color = FLinearColor::Red;

  const UCesiumGltfPrimitiveComponent* cesiumGltfPrimitiveComponent =
      Cast<const UCesiumGltfPrimitiveComponent>(Component);
  if (cesiumGltfPrimitiveComponent) {

    FVector min, max;
    cesiumGltfPrimitiveComponent->GetLocalBounds(min, max);

    float distance = FVector::Distance(min, View->ViewLocation);
    // UE_LOG(
    //		LogActor,
    //		Warning,
    //		TEXT("Visualize %s distance %f"),
    //		*Component->GetName(), distance);
    // thickness = 0.01f * distance;

    const FTransform& transform =
        cesiumGltfPrimitiveComponent->GetComponentTransform();
    min = transform.TransformPosition(min);
    max = transform.TransformPosition(max);

    // min += cesiumGltfPrimitiveComponent->GetComponentLocation();
    // max += cesiumGltfPrimitiveComponent->GetComponentLocation();

    FVector p000(min.X, min.Y, min.Z);
    FVector p001(min.X, min.Y, max.Z);
    FVector p010(min.X, max.Y, min.Z);
    FVector p011(min.X, max.Y, max.Z);
    FVector p100(max.X, min.Y, min.Z);
    FVector p101(max.X, min.Y, max.Z);
    FVector p110(max.X, max.Y, min.Z);
    FVector p111(max.X, max.Y, max.Z);

    // Front
    PDI->DrawLine(p000, p001, color, depthPriority, thickness);
    PDI->DrawLine(p001, p011, color, depthPriority, thickness);
    PDI->DrawLine(p011, p010, color, depthPriority, thickness);
    PDI->DrawLine(p010, p000, color, depthPriority, thickness);

    // Back
    PDI->DrawLine(p100, p101, color, depthPriority, thickness);
    PDI->DrawLine(p101, p111, color, depthPriority, thickness);
    PDI->DrawLine(p111, p110, color, depthPriority, thickness);
    PDI->DrawLine(p110, p100, color, depthPriority, thickness);

    // Edges
    PDI->DrawLine(p000, p100, color, depthPriority, thickness);
    PDI->DrawLine(p001, p101, color, depthPriority, thickness);
    PDI->DrawLine(p010, p110, color, depthPriority, thickness);
    PDI->DrawLine(p011, p111, color, depthPriority, thickness);
  }

  /*
  const UCesiumGltfComponent* cesiumGltfComponent = Cast<const
UCesiumGltfComponent>(Component); TArray<USceneComponent*> childrenComponents;
cesiumGltfComponent->GetChildrenComponents(false, childrenComponents);
  for (USceneComponent* childComponent : childrenComponents)
  {
          const UCesiumGltfPrimitiveComponent* cesiumGltfPrimitiveComponent =
Cast<const UCesiumGltfPrimitiveComponent>(childComponent); if
(cesiumGltfPrimitiveComponent) {

                  FVector min, max;
                  cesiumGltfPrimitiveComponent->GetLocalBounds(min, max);
                  FVector p000(min.X, min.Y, min.Z);
                  FVector p001(min.X, min.Y, max.Z);
                  FVector p010(min.X, max.Y, min.Z);
                  FVector p011(min.X, max.Y, max.Z);
                  FVector p100(max.X, min.Y, min.Z);
                  FVector p101(max.X, min.Y, max.Z);
                  FVector p110(max.X, max.Y, min.Z);
                  FVector p111(max.X, max.Y, max.Z);

                  // Front
                  PDI->DrawLine(p000, p001, color, depthPriority, thickness);
                  PDI->DrawLine(p001, p011, color, depthPriority, thickness);
                  PDI->DrawLine(p011, p010, color, depthPriority, thickness);
                  PDI->DrawLine(p010, p000, color, depthPriority, thickness);

                  // Back
                  PDI->DrawLine(p100, p101, color, depthPriority, thickness);
                  PDI->DrawLine(p101, p111, color, depthPriority, thickness);
                  PDI->DrawLine(p111, p110, color, depthPriority, thickness);
                  PDI->DrawLine(p110, p100, color, depthPriority, thickness);

                  // Edges
                  PDI->DrawLine(p000, p100, color, depthPriority, thickness);
                  PDI->DrawLine(p001, p101, color, depthPriority, thickness);
                  PDI->DrawLine(p010, p110, color, depthPriority, thickness);
                  PDI->DrawLine(p011, p111, color, depthPriority, thickness);
          }
}
  */
}
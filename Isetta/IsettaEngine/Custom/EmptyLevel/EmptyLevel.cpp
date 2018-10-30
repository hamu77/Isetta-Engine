/*
 * Copyright (c) 2018 Isetta
 */
#include "Custom/EmptyLevel/EmptyLevel.h"
#include "Application.h"
#include "Core/Config/Config.h"
#include "Custom/IsettaCore.h"
#include "Graphics/CameraComponent.h"

#include "Custom/Console.h"

namespace Isetta {

using CameraProperty = CameraComponent::Property;

void EmptyLevel::LoadLevel() {
  Entity* cameraEntity{AddEntity("Camera")};
  CameraComponent* camComp =
      cameraEntity->AddComponent<CameraComponent, true>("Camera");
  cameraEntity->SetTransform(Math::Vector3{0, 5, 10}, Math::Vector3{-15, 0, 0},
                             Math::Vector3::one);
  camComp->SetProperty<CameraProperty::FOV>(
      CONFIG_VAL(renderConfig.fieldOfView));
  camComp->SetProperty<CameraProperty::NEAR_PLANE>(
      CONFIG_VAL(renderConfig.nearClippingPlane));
  camComp->SetProperty<CameraProperty::FAR_PLANE>(
      CONFIG_VAL(renderConfig.farClippingPlane));

  // Application::Exit();
  cameraEntity->AddComponent<Console>("Console", true);
}
}  // namespace Isetta
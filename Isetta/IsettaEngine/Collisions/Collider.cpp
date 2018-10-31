/*
 * Copyright (c) 2018 Isetta
 */
#include "Collisions/Collider.h"
#include "Collisions/CollisionHandler.h"
#include "Collisions/CollisionsModule.h"

#include "Collisions/Ray.h"
#include "Scene/Entity.h"

namespace Isetta {
CollisionsModule* Collider::collisionsModule{nullptr};
float Collider::fatFactor = 0.f;

void Collider::Start() {
  if (!handler) FindHandler();
  // TODO(Yidi + Jacob)
  // hierarchyHandle =
  // entity->OnHierarchyChange.Register(std::bind(&Collider::FindHandler,this));
}

void Collider::OnEnable() {
  // TODO(Yidi) add AABB
  collisionsModule->colliders.insert(this);
  // TODO(Yidi + Jacob)
  // entity->OnHierarchyChange.Unregister(hierarchyHandle);
}

void Collider::AddToBVTree() {
  collisionsModule->bvTree.AddCollider(this);
}

void Collider::OnDisable() {
  // TODO(Yidi) remove AABB
  collisionsModule->colliders.erase(this);
}
void Collider::FindHandler() {
  handler = entity->GetComponent<CollisionHandler>();
  Transform* parent = GetTransform()->GetParent();
  while (parent && !handler) {
    handler = parent->GetEntity()->GetComponent<CollisionHandler>();
    parent = parent->GetParent();
  }
}
void Collider::RaycastHitCtor(RaycastHit* const hitInfo, const float distance,
                              const Math::Vector3& point,
                              const Math::Vector3& normal) {
  *hitInfo = RaycastHit{this, distance, point, normal.Normalized()};
}

}  // namespace Isetta

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/entity/extention_catalogue/CubicEntityPhysics.h"
#include "mojgame/auxiliary/glm_aux.h"
#include "mojgame/includer/bullet_include.h"
#include "mojgame/logging/Logger.h"

namespace mojgame {

bool CubicEntityPhysics::Initialize(btScalar mass, btCollisionShape &shape,
                                    btScalar restitution) {
  bt_motion_ = new CubicEntityMotionState(entity());
  if (bt_motion_ == nullptr) {
    LOGGER().Error("Failed to allocate for Bullet motion state object");
    CleanObjects();
    return false;
  }

  btVector3 local_inertia;
  shape.calculateLocalInertia(mass, local_inertia);
  btRigidBody::btRigidBodyConstructionInfo body_ci(mass, bt_motion_, &shape,
                                                   local_inertia);
  body_ci.m_restitution = restitution;
  bt_body_ = new btRigidBody(body_ci);
  if (bt_body_ == nullptr) {
    LOGGER().Error("Failed to allocate for Bullet rigid body object");
    CleanObjects();
    return false;
  }
  return true;
}

void CubicEntityPhysics::Finalize() {
  CleanObjects();
  bt_body_ = nullptr;
  bt_motion_ = nullptr;
}

void CubicEntityPhysics::CleanObjects() {
  delete bt_body_;
  delete bt_motion_;
}

} /* namespace mojgame */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/sampler/physics_constant.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace PhysicsConstant {
const float kGravityMagnitude = 9.80665f; // (m/s2)
const glm::vec3 kGravity = glm::vec3(0.0f, kGravityMagnitude * -1.0f, 0.0f);
}

} /* namespace mojgame */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/camera/Camera.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

Camera::Camera(const glm::vec3& pos, const glm::vec3& at, const glm::vec3& up)
    : default_pos_(pos),
      default_at_(at),
      default_up_(up),
      pos_(pos),
      at_(at),
      up_(glm::normalize(up)) {
}

Camera::~Camera() {
}

} /* namespace mojgame */

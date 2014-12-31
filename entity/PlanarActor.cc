/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/entity/PlanarActor.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

bool PlanarActor::Step(float elapsed_time) {
  if (walking_) {
    float approachable = walk_speed_ * elapsed_time;
    glm::vec2 to_dst = walk_dst_ - pos();
    float distance = glm::length(to_dst);
    if (!mojgame::math_aux::is_fpositive(distance)
        || approachable > glm::length(to_dst)) {
      walking_ = false;
      set_pos(walk_dst_);
    } else {
      set_pos(pos() + glm::normalize(to_dst) * approachable);
    }
    set_rot(atan2(to_dst.y, to_dst.x));
  }
  return OnStep(elapsed_time);
}

void PlanarActor::Appear(const glm::vec2 &pos, float rot,
                         const glm::vec2 &size) {
  set_pos(pos);
  set_rot(rot);
  set_size(size);
  appeared_ = true;
  walking_ = false;
}

void PlanarActor::Disappear() {
  appeared_ = false;
  walking_ = false;
}

void PlanarActor::Walk(const glm::vec2 &dst) {
  if (appeared_) {
    walking_ = true;
    walk_dst_ = dst;
  } else {
    mojgame::LOGGER().Warn("Cannot walk so that not appeared");
  }
}

} /* namespace mojgame */

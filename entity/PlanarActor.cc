/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/entity/PlanarActor.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

bool PlanarActor::Step(float elapsed_time) {
  if (walk_target_ != nullptr) {
    float approachable = walk_speed_ * elapsed_time;
    glm::vec2 to_dst = walk_target_->pos() - pos();
    float distance = glm::length(to_dst);
    if (!mojgame::math_aux::is_fpositive(distance)
        || approachable > glm::length(to_dst)) {
      set_pos(walk_target_->pos());
      walk_target_ = nullptr;
      OnWalkFinished();
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
  walk_target_ = nullptr;
}

void PlanarActor::Disappear() {
  appeared_ = false;
  walk_target_ = nullptr;
}

void PlanarActor::Walk(const glm::vec2 &dst) {
  if (appeared_) {
    dummy_entity_.set_pos(dst);
    walk_target_ = &dummy_entity_;
  } else {
    mojgame::LOGGER().Warn("Cannot walk so that not appeared");
  }
}

void PlanarActor::Walk(const mojgame::PlanarEntity &target) {
  if (appeared_) {
    walk_target_ = &target;
  } else {
    mojgame::LOGGER().Warn("Cannot walk so that not appeared");
  }
}

void PlanarActor::Stop() {
  walk_target_ = nullptr;
  OnWalkFinished();
}

} /* namespace mojgame */

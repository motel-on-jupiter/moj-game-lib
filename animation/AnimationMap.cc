/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/animation/AnimationMap.h"
#include <map>
#include "mojgame/animation/Animation.h"

namespace mojgame {

Animation *AnimationMap::LookUp(AnimationType type,
                                AnimationDirection direction) {
  auto it = map_data_.find(CalcMapKey(type, direction));
  if (it == map_data_.end()) {
    return nullptr;
  }
  return &(it->second);
}

int AnimationMap::CalcMapKey(AnimationType type, AnimationDirection direction) {
  return type + (direction << 16);
}

} /* namespace mojgame */

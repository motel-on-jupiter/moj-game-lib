/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/animation/Animation.h"

namespace mojgame {

Animation::Animation()
    : frames_(),
      loopable_(false) {
}

const Animation::AnimationFrame *Animation::GetFrame(
    float time) const {
  int idx = GetFrameIdx(time);
  if (idx < 0) {
    return nullptr;
  }
  return &(frames_[idx]);
}

int Animation::GetFrameIdx(float time) const {
  if (time < 0.0f) {
    return -1;
  }
  for (unsigned int i = 0; i < frames_.size(); ++i) {
    if (time < frames_[i].time) {
      return i;
    }
    time -= frames_[i].time;
  }
  return -1;
}

int Animation::GetNumFrames() const {
 return frames_.size();
}

float Animation::GetFrameTime(float time) const {
  if (time < 0.0f) {
    return 0.0f;
  }
  for (unsigned int i = 0; i < frames_.size(); ++i) {
    if (time < frames_[i].time) {
      return time;
    }
    time -= frames_[i].time;
  }
  return 0.0f;
}

float Animation::GetEntireTime() const {
  float entire_time = 0.0f;
  for (auto it = frames_.begin(); it != frames_.end(); ++it) {
    entire_time += (*it).time;
  }
  return entire_time;
}

} /* namespace mojgame */

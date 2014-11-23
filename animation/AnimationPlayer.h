/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_ANIMATION_ANIMATIONPLAYER_H_
#define MOJGAMELIB_ANIMATION_ANIMATIONPLAYER_H_

#include "mojgame/animation/Animation.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

class AnimationPlayer : public mojgame::NonCopyable<AnimationPlayer> {
 public:
  AnimationPlayer()
      : anim_(nullptr),
        anim_time_(0.0f) {

  }
  virtual ~AnimationPlayer() {
  }

  void Play(const Animation *anim) {
    if (anim_ != anim) {
      anim_ = anim;
      anim_time_ = 0.0f;
    }
  }
  void Restart() {
    anim_time_ = 0.0f;
  }
  void Stop() {
    anim_ = nullptr;
    anim_time_ = 0.0f;
  }

  void OnFrame(float elapsed_time) {
    if (anim_ != nullptr) {
      anim_time_ += elapsed_time;
      if (anim_->loopable()) {
        float entire_time = anim_->GetEntireTime();
        if (anim_time_ >= entire_time) {
          anim_time_ -= entire_time;
        }
      }
    }
  }

  const Animation *anim() const {
    return anim_;
  }
  float anim_time() const {
    return anim_time_;
  }

 private:
  const Animation *anim_;
  float anim_time_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ANIMATION_ANIMATIONPLAYER_H_ */

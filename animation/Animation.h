/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_ANIMATION_ANIMATION_H_
#define MOJGAMELIB_ANIMATION_ANIMATION_H_

#include <vector>

namespace mojgame {

class Animation {
 public:
  enum AnimationEffect {
    kAnimationBlink = 1 << 0,
    kAnimationColored = 1 << 1,
  };
  struct AnimationFrame {
    float time;
    int resource_id;
    int effects;
  };

  Animation();
  virtual ~Animation() {
  }

  const AnimationFrame *GetFrame(float time) const;
  int GetFrameIdx(float time) const;
  int GetNumFrames() const;
  float GetFrameTime(float time) const;
  float GetEntireTime() const;

  std::vector<AnimationFrame>& frames() {
    return frames_;
  }
  bool loopable() const {
    return loopable_;
  }
  void set_loopable(bool loopable) {
    loopable_ = loopable;
  }

 private:
  std::vector<AnimationFrame> frames_;
  bool loopable_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ANIMATION_ANIMATION_H_ */

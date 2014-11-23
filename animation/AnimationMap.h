/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_ANIMATION_ANIMATIONMAP_H_
#define MOJGAMELIB_ANIMATION_ANIMATIONMAP_H_

#include <map>
#include "mojgame/animation/Animation.h"

namespace mojgame {

class AnimationMap {
 public:
  enum AnimationType {
    kAnimationIdle,
    kAnimationWalk,
    kAnimationDamaged,
    kAnimationChant,
  /* max number is (2^16)-1 */
  };
  enum AnimationDirection {
    kAnimationFront,
    kAnimationBack,
    kAnimationRight,
    kAnimationLeft,
  /* max number is (2^16)-1 */
  };
  AnimationMap()
      : map_data_() {
  }
  virtual ~AnimationMap() {
  }

  virtual bool Build() = 0;
  virtual void Unbuild() = 0;

  Animation *LookUp(AnimationType type, AnimationDirection direction);

 protected:
  static int CalcMapKey(AnimationType type, AnimationDirection direction);

  std::map<int, Animation> &map_data() {
    return map_data_;
  }

 private:
  std::map<int, Animation> map_data_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ANIMATION_ANIMATIONMAP_H_ */

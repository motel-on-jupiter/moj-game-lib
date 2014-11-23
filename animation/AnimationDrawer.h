/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_ANIMATION_ANIMATIONDRAWER_H_
#define MOJGAMELIB_ANIMATION_ANIMATIONDRAWER_H_

#include "mojgame/animation/Animation.h"
#include "mojgame/animation/AnimationResource.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

class AnimationDrawer : public mojgame::NonCopyable<
    AnimationDrawer> {
 public:
  AnimationDrawer(const AnimationResource &resource);
  virtual ~AnimationDrawer() {
  }

  void Draw(const Animation *animation, float time,
            const glm::vec2 &translation, float rotation,
            const glm::vec2 &scaling);

 private:
  const AnimationResource &resource_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ANIMATION_ANIMATIONDRAWER_H_ */

/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAME_CATALOGUE_RENDERER_RIPPLERENDERER_H_
#define MOJGAME_CATALOGUE_RENDERER_RIPPLERENDERER_H_

#include <vector>
#include "mojgame/catalogue/renderer/GradationalRenderer.h"

namespace mojgame {

struct RippleStimulus {
  glm::vec2 pos;
  float force;

  RippleStimulus()
      : pos(),
        force(0.0f) {
  }
  RippleStimulus(glm::vec2 pos, float force)
      : pos(pos),
        force(force) {
  }
  void Clear() {
    force = 0.0f;
  }
};

class RippleGLRenderer : public GradationalGLRenderer {
 public:
  RippleGLRenderer();
  virtual ~RippleGLRenderer() {
  }

  void Stimulate(const RippleStimulus &stimulus) {
    stimulus_ = stimulus;
  }

 protected:
  virtual bool OnRendering(const glm::vec2 &window_size);

 private:
  RippleStimulus stimulus_;
};

} /* namespace mojgame */

#endif /* MOJGAME_CATALOGUE_RENDERER_RIPPLERENDERER_H_ */

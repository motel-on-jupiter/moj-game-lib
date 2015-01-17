/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_RENDERER_RENDERER_H_
#define MOJGAMELIB_RENDERER_RENDERER_H_

#include "mojgame/auxiliary/csyntax_aux.h"

namespace mojgame {

class BaseRenderer : public mojgame::NonCopyable<BaseRenderer> {
 public:
  BaseRenderer()
      : initialized_(false) {
  }
  virtual ~BaseRenderer() {
  }
  bool Render(const glm::vec2 &window_size) {
    if (initialized_) {
      return OnRendering(window_size);
    }
    return true;
  }

 protected:
  virtual bool OnRendering(const glm::vec2 &window_size) = 0;
  void set_initialized(bool initialized) {
    initialized_ = initialized;
  }

 private:
  bool initialized_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_RENDERER_RENDERER_H_ */

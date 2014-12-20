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

  bool Initialize(const glm::vec2 &window_size) {
    if (initialized_) {
      return true;
    }
    initialized_ = true;
    return OnInitial(window_size);
  }
  void Finalize() {
    if (initialized_) {
      OnFinal();
      initialized_ = false;
    }
  }
  bool Render(const glm::vec2 &window_size) {
    if (initialized_) {
      return OnRendering(window_size);
    }
    return true;
  }

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) = 0;
  virtual void OnFinal() = 0;
  virtual bool OnRendering(const glm::vec2 &window_size) = 0;

 private:
  bool initialized_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_RENDERER_RENDERER_H_ */

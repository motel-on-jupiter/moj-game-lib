/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_RENDERER_RENDERER_H_
#define MOJGAMELIB_RENDERER_RENDERER_H_

namespace mojgame {

class RendererInterface {
 public:
  RendererInterface() {
  }
  virtual ~RendererInterface() {
  }

  virtual bool Initialize(const glm::vec2 &window_size) = 0;
  virtual void Finalize() = 0;
  virtual bool Render(const glm::vec2 &window_size) = 0;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_RENDERER_RENDERER_H_ */

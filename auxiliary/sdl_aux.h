/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_SDLAUX_H_
#define MOJGAMELIB_AUXILIARY_SDLAUX_H_

#include "mojgame/includer/sdl_include.h"

namespace mojgame {

namespace sdl_aux {

class KeyboardEventListenerInterface {
 public:
  virtual ~KeyboardEventListenerInterface() {
  }
  virtual bool React(const SDL_KeyboardEvent &keyboard) = 0;
};

class MouseEventListenerInterface {
 public:
  virtual ~MouseEventListenerInterface() {
  }
  virtual bool React(const SDL_MouseMotionEvent &motion,
                     const glm::vec2 &window_size) = 0;
  virtual bool React(const SDL_MouseButtonEvent &button,
                     const glm::vec2 &window_size) = 0;
  virtual bool React(const SDL_MouseWheelEvent &wheel,
                     const glm::vec2 &window_size) = 0;
};

// TODO: event listener for each event

} /* namespace sdl_aux */

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_SDLAUX_H_ */

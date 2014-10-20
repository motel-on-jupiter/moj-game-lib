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
  virtual void React(const SDL_KeyboardEvent &keyboard) = 0;
};

class MouseEventListenerInterface {
 public:
  virtual ~MouseEventListenerInterface() {
  }
  virtual void React(const SDL_MouseMotionEvent &motion) = 0;
  virtual void React(const SDL_MouseButtonEvent &button) = 0;
  virtual void React(const SDL_MouseWheelEvent &wheel) = 0;
};

// TODO: event listener for each event

} /* namespace sdl_aux */

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_SDLAUX_H_ */

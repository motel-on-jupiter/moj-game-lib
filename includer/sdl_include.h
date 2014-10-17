/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_INCLUDER_SDLINCLUDE_H_
#define MOJGAMELIB_INCLUDER_SDLINCLUDE_H_

#include "mojgame/includer/gl_include.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

#undef WIN32_LEAN_AND_MEAN
#include <SDL_opengl.h>

// device input
#include <SDL_gesture.h>
#include <SDL_joystick.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>
#include <SDL_scancode.h>
#include <SDL_touch.h>

#endif /* MOJGAMELIB_INCLUDER_SDLINCLUDE_H_ */

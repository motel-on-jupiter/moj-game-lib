/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_CAMERACONTROLLER_FIRSTPERSONCAMERACONTROLLER_H_
#define MOJGAMELIB_CATALOGUE_CAMERACONTROLLER_FIRSTPERSONCAMERACONTROLLER_H_

#include <set>
#include "mojgame/camera/CameraController.h"
#include "mojgame/includer/sdl_include.h"

class Camera;

namespace mojgame {

class FirstPersonCameraController : public mojgame::BaseCameraController {
 public:
  FirstPersonCameraController(Camera &camera, float translate_speed,
                              float rotate_speed);
  virtual ~FirstPersonCameraController();

  virtual void Update(float elapsed_time);
  virtual void OnKeyDown(const SDL_KeyboardEvent &keyboard);
  virtual void OnKeyUp(const SDL_KeyboardEvent &keyboard);
  virtual void OnMouseMotion(const SDL_MouseMotionEvent &motion);
  virtual void OnMouseButtonDown(const SDL_MouseButtonEvent &button);
  virtual void OnMouseWheel(const SDL_MouseWheelEvent &wheel);

 private:
  float translate_speed_;
  float rotate_speed_;
  std::set<SDL_Keycode> pressing_key_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_CAMERACONTROLLER_FIRSTPERSONCAMERACONTROLLER_H_ */

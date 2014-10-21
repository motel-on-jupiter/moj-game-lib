/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_CAMERACONTROLLER_DESIGNERCAMERACONTROLLER_H_
#define MOJGAMELIB_CATALOGUE_CAMERACONTROLLER_DESIGNERCAMERACONTROLLER_H_

#include "mojgame/camera/CameraController.h"

class Camera;

namespace mojgame {

class DesignerCameraController : public BaseCameraController {
 public:
  DesignerCameraController(Camera &camera, float translate_speed,
                           float rotate_speed, float zoom_speed);
  virtual ~DesignerCameraController();

  virtual void Update(float elapsed_time);
  virtual void OnKeyDown(const SDL_KeyboardEvent &keyboard);
  virtual void OnKeyUp(const SDL_KeyboardEvent &keyboard);
  virtual void OnMouseMotion(const SDL_MouseMotionEvent &motion);
  virtual void OnMouseButtonDown(const SDL_MouseButtonEvent &button);
  virtual void OnMouseWheel(const SDL_MouseWheelEvent &wheel);

 private:
  struct Option {
    float translate_speed;
    float rotate_speed;
    float zoom_speed;
  } option_;
  struct MouseStat {
    int x;
    int y;
    unsigned char button;
    unsigned char state;
  } mouse_stat_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CAMERA_CONTROLLERCATALOGUE_DESIGNERCAMERACONTROLLER_H_ */

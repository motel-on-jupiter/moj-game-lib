/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CAMERA_CAMERACONTROLLER_H_
#define MOJGAMELIB_CAMERA_CAMERACONTROLLER_H_

#include "mojgame/auxiliary/csyntax_aux.h"

namespace mojgame {

class Camera;

class BaseCameraController : public NonCopyable<BaseCameraController> {
 public:
  BaseCameraController(Camera &camera)
      : camera_(camera) {
  }
  virtual ~BaseCameraController() {
  }

  virtual void Update(float elapsed_time) = 0;
  virtual void OnKeyDown(const SDL_KeyboardEvent &keyboard) = 0;
  virtual void OnKeyUp(const SDL_KeyboardEvent &keyboard) = 0;
  virtual void OnMouseMotion(const SDL_MouseMotionEvent &motion) = 0;
  virtual void OnMouseButtonDown(const SDL_MouseButtonEvent &event) = 0;
  virtual void OnMouseWheel(const SDL_MouseWheelEvent &event) = 0;

 protected:
  Camera &camera() {
    return camera_;
  }

 private:
  Camera &camera_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CAMERA_CAMERACONTROLLER_H_ */

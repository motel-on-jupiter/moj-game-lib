/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/camera_controller/DesignerCameraController.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/auxiliary/math_aux.h"
#include "mojgame/camera/Camera.h"
#include "mojgame/camera/CameraController.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/sdl_include.h"

namespace mojgame {

DesignerCameraController::DesignerCameraController(Camera &camera,
                                                   float translate_speed,
                                                   float rotate_speed,
                                                   float zoom_speed)
    : BaseCameraController(camera),
      option_(),
      mouse_stat_() {
  option_.translate_speed = translate_speed;
  option_.rotate_speed = rotate_speed;
  option_.zoom_speed = zoom_speed;
  mouse_stat_.x = 0;
  mouse_stat_.y = 0;
  mouse_stat_.button = SDL_BUTTON_LEFT;
  mouse_stat_.state = SDL_RELEASED;
}

DesignerCameraController::~DesignerCameraController() {
}

void DesignerCameraController::Update(float elapsed_time) {
  UNUSED(elapsed_time);
}

void DesignerCameraController::OnKeyDown(const SDL_KeyboardEvent &keyboard) {
  UNUSED(keyboard);
}

void DesignerCameraController::OnKeyUp(const SDL_KeyboardEvent &keyboard) {
  UNUSED(keyboard);
}

void DesignerCameraController::OnMouseMotion(
    const SDL_MouseMotionEvent &motion) {
  if (mouse_stat_.state == SDL_PRESSED) {
    float delta_x = static_cast<float>(mouse_stat_.x - motion.x);
    float delta_y = static_cast<float>(mouse_stat_.y - motion.y);
    glm::vec3 right = camera().BuildRightDir();

    if (mouse_stat_.button == SDL_BUTTON_RIGHT) {
      glm::vec3 local = camera().pos() - camera().at();
      glm::vec3 rotated = glm::rotate(local, delta_y * option_.rotate_speed,
                                      right);
      rotated = glm::rotate(rotated, delta_x * option_.rotate_speed,
                            camera().up());
      camera().set_pos(rotated + camera().at());
      camera().set_up(
          glm::rotate(camera().up(), delta_y * option_.rotate_speed, right));
    } else if (SDL_BUTTON_MIDDLE == mouse_stat_.button) {
      glm::vec3 move = camera().up() * delta_y * option_.translate_speed;
      move += right * delta_x * option_.translate_speed * -1.0f;
      camera().set_pos(camera().pos() + move);
      camera().set_at(camera().at() + move);
    }
  }

  mouse_stat_.x = motion.x;
  mouse_stat_.y = motion.y;
}

void DesignerCameraController::OnMouseButtonDown(
    const SDL_MouseButtonEvent &button) {
  mouse_stat_.x = button.x;
  mouse_stat_.y = button.y;
  mouse_stat_.button = button.button;
  mouse_stat_.state = button.state;
}

void DesignerCameraController::OnMouseWheel(const SDL_MouseWheelEvent &wheel) {
  camera().set_pos(
      camera().pos()
          + camera().BuildForwardDir() * option_.zoom_speed
              * math_aux::sign(static_cast<float>(wheel.y)));
}

} /* namespace mojgame */

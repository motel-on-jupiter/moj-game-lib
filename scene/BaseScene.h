/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SCENE_BASESCENE_H_
#define MOJGAMELIB_SCENE_BASESCENE_H_

#include <string>

namespace mojgame {

class BaseScene {
 public:
  BaseScene(const char *name)
      : name_(name),
        finished_(true),
        scene_time_(0.0f) {
  }
  virtual ~BaseScene() {
  }

  int Initialize() {
    finished_ = false;
    scene_time_ = 0.0f;
    return OnInitial();
  }
  void Finalize() {
    OnFinal();
  }
  void Step(float elapsed_time) {
    scene_time_ += elapsed_time;
    OnStep(elapsed_time);
  }

  virtual void Draw(const glm::vec2 &window_size) = 0;
  virtual void OnKeyDown(const SDL_KeyboardEvent &key) = 0;
  virtual void OnKeyUp(const SDL_KeyboardEvent &key) = 0;
  virtual void OnMouseButtonDown(const SDL_MouseButtonEvent &button) = 0;
  virtual void OnMouseMotion(const SDL_MouseMotionEvent &motion) = 0;

  const std::string &name() const {
    return name_;
  }
  bool finished() const {
    return finished_;
  }
  float scene_time() const {
    return scene_time_;
  }

 protected:
  virtual int OnInitial() = 0;
  virtual void OnFinal() = 0;
  virtual void OnStep(float elapsed_time) = 0;

  void set_finished(bool finished) {
    finished_ = finished;
  }

 private:
  std::string name_;
  bool finished_;
  float scene_time_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_BASESCENE_H_ */

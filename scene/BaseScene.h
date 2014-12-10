/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SCENE_BASESCENE_H_
#define MOJGAMELIB_SCENE_BASESCENE_H_

#include <string>

namespace mojgame {

class BaseSceneRenderer {
 public:
  BaseSceneRenderer(BaseScene &scene)
      : scene_(scene),
        initialized_(true) {
  }
  virtual ~BaseSceneRenderer();

  bool Initialize() {
    if (initialized_) {
      return true;
    }
    initialized_ = true;
    return OnInitial();
  }
  void Finalize() {
    if (initialized_) {
      OnFinal();
      initialized_ = false;
    }
  }
  virtual bool Render(const glm::vec2 &window_size) {
    if (initialized_) {
      return OnRendering(window_size);
    }
    return true;
  }

 protected:
  virtual bool OnInitial() = 0;
  virtual void OnFinal() = 0;
  virtual bool OnRendering(const glm::vec2 &window_size) = 0;

 private:
  BaseScene &scene_;
  bool initialized_;
};

class BaseScene {
 public:
  BaseScene(const char *name)
      : name_(name),
        initialized_(true),
        scene_time_(0.0f) {
  }
  virtual ~BaseScene() {
  }

  bool Initialize() {
    if (initialized_) {
      return true;
    }
    initialized_ = false;
    scene_time_ = 0.0f;
    return OnInitial();
  }
  void Finalize() {
    if (initialized_) {
      OnFinal();
      initialized_ = true;
    }
  }
  bool Step(float elapsed_time) {
    if (initialized_) {
      scene_time_ += elapsed_time;
      return OnStep(elapsed_time);
    }
    return true;
  }

  const std::string &name() const {
    return name_;
  }
  float scene_time() const {
    return scene_time_;
  }

 protected:
  virtual bool OnInitial() = 0;
  virtual void OnFinal() = 0;
  virtual bool OnStep(float elapsed_time) = 0;

 private:
  std::string name_;
  bool initialized_;
  float scene_time_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_BASESCENE_H_ */

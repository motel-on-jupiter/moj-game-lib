/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SCENE_SCENE_H_
#define MOJGAMELIB_SCENE_SCENE_H_

#include <string>
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/renderer/Renderer.h"

namespace mojgame {

class BaseScene {
 public:
  explicit BaseScene(const char *name)
      : name_(name),
        initialized_(false),
        time_(0.0f),
        finished_(true) {
  }
  virtual ~BaseScene() {
  }

  bool Initialize(const glm::vec2 &window_size) {
    if (initialized_) {
      return true;
    }
    if (!OnInitial(window_size)) {
      return false;
    }
    initialized_ = true;
    time_ = 0.0f;
    finished_ = false;
    return true;
  }
  void Finalize() {
    if (initialized_) {
      OnFinal();
      initialized_ = false;
    }
  }
  bool Step(float elapsed_time) {
    if (initialized_) {
      time_ += elapsed_time;
      return OnStep(elapsed_time);
    }
    return true;
  }
  bool Render(const glm::vec2 &window_size) {
    if (initialized_) {
      return OnRendering(window_size);
    }
    return true;
  }

  const std::string &name() const {
    return name_;
  }
  bool initialized() const {
    return initialized_;
  }
  float time() const {
    return time_;
  }
  bool finished() const {
    return finished_;
  }

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) = 0;
  virtual void OnFinal() = 0;
  virtual bool OnStep(float elapsed_time) = 0;
  virtual bool OnRendering(const glm::vec2 &window_size) = 0;

  void Finish() {
    finished_ = true;
  }

 private:
  std::string name_;
  bool initialized_;
  float time_;
  bool finished_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_SCENE_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SCENE_SCENERENDERER_H_
#define MOJGAMELIB_SCENE_SCENERENDERER_H_

#include <string>
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/scene/Scene.h"

namespace mojgame {

class BaseSceneRenderer : public mojgame::NonCopyable<BaseSceneRenderer> {
 public:
  explicit BaseSceneRenderer(BaseScene &scene)
      : scene_(scene),
        initialized_(false) {
  }
  virtual ~BaseSceneRenderer() {
  }

  bool Initialize(const glm::vec2 &window_size) {
    if (initialized_) {
      return true;
    }
    if (!scene_.initialized()) {
      mojgame::LOGGER().Error("Scene object is not initialized");
      return false;
    }
    initialized_ = true;
    return OnInitial(window_size);
  }
  void Finalize() {
    if (initialized_) {
      OnFinal();
      initialized_ = false;
    }
  }
  bool Render(const glm::vec2 &window_size) {
    if (initialized_) {
      return OnRendering(window_size);
    }
    return true;
  }

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) = 0;
  virtual void OnFinal() = 0;
  virtual bool OnRendering(const glm::vec2 &window_size) = 0;

  BaseScene &scene() {
    return scene_;
  }

 private:
  BaseScene &scene_;
  bool initialized_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_SCENERENDERER_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SCENE_SCENESUITE_H_
#define MOJGAMELIB_SCENE_SCENESUITE_H_

#include <string>
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/scene/Scene.h"
#include "mojgame/scene/SceneRenderer.h"

namespace mojgame {

class BaseSceneSuite : public mojgame::NonCopyable<BaseSceneSuite> {
 public:
  BaseSceneSuite(BaseScene &scene, BaseSceneRenderer &renderer)
      : mojgame::NonCopyable<BaseSceneSuite>(),
        scene_(scene),
        renderer_(renderer) {
  }
  virtual ~BaseSceneSuite() {
  }

  bool Initialize(const glm::vec2 &window_size) {
    return scene_.Initialize() && renderer_.Initialize(window_size);
  }
  void Finalize() {
    renderer_.Finalize();
    scene_.Finalize();
  }
  bool Step(float elapsed_time) {
    return scene_.Step(elapsed_time);
  }
  bool Render(const glm::vec2 &window_size) {
    return renderer_.Render(window_size);
  }

  BaseScene &scene() {
    return scene_;
  }
  BaseSceneRenderer &renderer() {
    return renderer_;
  }

 private:
  BaseScene &scene_;
  BaseSceneRenderer &renderer_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_SCENESUITE_H_ */

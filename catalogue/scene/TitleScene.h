/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_
#define MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/scene/SceneRenderer.h"

namespace mojgame {

class TitleSceneGLRenderer : public BaseSceneRenderer {
 public:
  TitleSceneGLRenderer(BaseScene &scene)
      : BaseSceneRenderer(scene) {
  }
  virtual ~TitleSceneGLRenderer() {
  }

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) {
    UNUSED(window_size);

    return true;
  }
  virtual void OnFinal() {
  }
  virtual bool OnRendering(const glm::vec2 &window_size);
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_
#define MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/catalogue/renderer/TelopRenderer.h"
#include "mojgame/scene/Scene.h"

namespace mojgame {

class GLTitleTelopRenderer : public GLTelopRenderer {
 public:
  GLTitleTelopRenderer() : GLTelopRenderer("PRESS ENTER KEY", glm::vec2(0.5f)) {
  }
};

class GLTitleScene : public RendererAttachableScene {
 public:
  explicit GLTitleScene(const char *name = "Title")
      : RendererAttachableScene(name, &renderer_),
        renderer_() {
  }
  virtual ~GLTitleScene() {
  }

 protected:
  bool OnStep(float elapsed_time) {
    UNUSED(elapsed_time);
    return true;
  }
  bool OnRendering(const glm::vec2& window_size);

 private:
  GLTitleTelopRenderer renderer_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_ */

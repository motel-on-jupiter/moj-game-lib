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

class GLTitleScene : public BaseScene {
 public:
  explicit GLTitleScene(const char *name = "Title")
      : BaseScene(name),
        renderer_() {
  }
  virtual ~GLTitleScene() {
  }

 protected:
  bool OnInitial(const glm::vec2 &window_size) {
    UNUSED(window_size);
    return renderer_.Initialize();
  }
  void OnFinal() {
    renderer_.Finalize();
  }
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

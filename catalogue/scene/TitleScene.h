/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_
#define MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/scene/Scene.h"

namespace mojgame {

class TitleScene : public BaseScene {
 public:
  explicit TitleScene(const char *name = "Title")
      : BaseScene(name) {
  }
  virtual ~TitleScene() {
  }

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) {
    UNUSED(window_size);
    return true;
  }
  virtual void OnFinal() {
  }
  virtual bool OnStep(float elapsed_time) {
    UNUSED(elapsed_time);
    return true;
  }
  virtual bool OnRendering(const glm::vec2 &window_size);
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_ */

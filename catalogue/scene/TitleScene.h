/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_
#define MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/renderer/Renderer.h"

namespace mojgame {

class TitleSceneGLRenderer : public BaseRenderer {
 public:
  TitleSceneGLRenderer()
      : BaseRenderer(),
        time_(0.0f) {
  }
  virtual ~TitleSceneGLRenderer() {
  }

  void Update(float time) {
    time_ = time;
  }

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) {
    UNUSED(window_size);

    return true;
  }
  virtual void OnFinal() {
  }
  virtual bool OnRendering(const glm::vec2 &window_size);

 private:
  float time_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_SCENE_TITLESCENE_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_SCENE_TITLESCENE_H_
#define MOJGAMELIB_SCENE_TITLESCENE_H_

#include "mojgame/scene/BaseScene.h"

struct SDL_KeyboardEvent;
struct SDL_MouseButtonEvent;
struct SDL_MouseMotionEvent;

namespace mojgame {

class TitleScene : public BaseScene {
 public:
  TitleScene(const char *name);
  virtual ~TitleScene();

  virtual void Draw(const glm::vec2 &window_size);
  virtual void OnKeyDown(const SDL_KeyboardEvent &keyboard);
  virtual void OnKeyUp(const SDL_KeyboardEvent &keyboard);
  virtual void OnMouseButtonDown(const SDL_MouseButtonEvent &button);
  virtual void OnMouseMotion(const SDL_MouseMotionEvent &motion);

 protected:
  virtual int OnInitial();
  virtual void OnFinal();
  virtual void OnStep(float elapsed_time);
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_TITLESCENE_H_ */

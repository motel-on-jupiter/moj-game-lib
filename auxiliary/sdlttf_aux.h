/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_SDLTTFAUX_H_
#define MOJGAMELIB_AUXILIARY_SDLTTFAUX_H_

#ifdef MOJGAMELIB_WITH_SDLTTF

#include "mojgame/includer/glm_include.h"
#include "mojgame/includer/sdl_include.h"
#include "mojgame/includer/sdlttf_include.h"

namespace mojgame {

class GLTTFText {
 public:
  GLTTFText()
      : initialized_(false),
        surface_(nullptr),
        texname_(0) {
  }
  ~GLTTFText() {
    Finalize();
  }
  bool Initialize(TTF_Font *font, const char *text, const SDL_Color& color);
  void Finalize();
  void Render(const glm::vec2 &position, float scale = 1.0f);

 private:
  bool initialized_;
  SDL_Surface *surface_;
  GLuint texname_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_SDLTTF */

#endif /* MOJGAMELIB_AUXILIARY_SDLTTFAUX_H_ */

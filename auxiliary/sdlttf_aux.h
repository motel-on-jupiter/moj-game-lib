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

namespace sdlttf_aux {

extern int RenderTTFText(TTF_Font *Font, const SDL_Color &Color,
                         const glm::vec2 &Position, const char *
                         Text);

} /* namespace sdlttf_aux */

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_SDLTTF */

#endif /* MOJGAMELIB_AUXILIARY_SDLTTFAUX_H_ */

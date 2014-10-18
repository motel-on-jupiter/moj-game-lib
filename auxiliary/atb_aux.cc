/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/atb_aux.h"

extern "C" {
#include "mojgame/external/TwEventSDL20.c"
}

namespace mojgame {

namespace atb_aux {

inline int TW_CALL TwEventSDL20(const void *sdlEvent) {
  return ::TwEventSDL20(sdlEvent);
}

} /* namespace atb_aux */

} /* namespace mojgame */

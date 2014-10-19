/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_GL_GLRENDERING_H_
#define MOJGAMELIB_AUXILIARY_GL_GLRENDERING_H_

#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace gl_rendering {

extern inline void clear_color_buffer();
extern inline void clear_depth_buffer();
extern inline void clear_stencil_buffer();

extern inline void fill_color_buffer(const glm::vec3 &color);

} /* namespace gl_rendering */

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_GL_GLRENDERING_H_ */

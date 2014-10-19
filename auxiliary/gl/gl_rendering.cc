/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/gl/gl_rendering.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace gl_rendering {

inline void clear_color_buffer() {
  fill_color_buffer(glm::vec3());
}

inline void clear_depth_buffer() {
  glClear(GL_DEPTH_BUFFER_BIT);
}

inline void clear_stencil_buffer() {
  glClear(GL_STENCIL_BUFFER_BIT);
}

inline void fill_color_buffer(const glm::vec3 &color) {
  glClearColor(color.r, color.g, color.b, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

} /* namespace gl_rendering */

} /* namespace mojgame */

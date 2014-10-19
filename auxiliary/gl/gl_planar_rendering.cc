/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/auxiliary/gl/gl_planar_rendering.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace gl_planar_rendering {

void set_up_matrix_stack(const glm::vec2 &window_size) {
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(
      glm::value_ptr(
          glm::ortho(0.0f, window_size.x, window_size.y, 0.0f, -1.0f, 1.0f)));
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

} /* namespace gl_planar_rendering */

} /* namespace mojgame */


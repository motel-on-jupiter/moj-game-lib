/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/gl/gl_rendering.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace gl_rendering {

inline void bind_1d_texture(GLuint unit, GLuint name) {
  glActiveTexture(unit);
  glBindTexture(GL_TEXTURE_1D, name);
}

inline void bind_2d_texture(GLuint unit, GLuint name) {
  glActiveTexture(unit);
  glBindTexture(GL_TEXTURE_2D, name);
}

inline void bind_3d_texture(GLuint unit, GLuint name) {
  glActiveTexture(unit);
  glBindTexture(GL_TEXTURE_3D, name);
}

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

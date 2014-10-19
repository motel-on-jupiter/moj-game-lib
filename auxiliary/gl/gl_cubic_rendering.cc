/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/auxiliary/gl/gl_cubic_rendering.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace gl_cubic_rendering {

inline void set_up_viewport(const glm::vec2 &window_size) {
  glViewport(0, 0, static_cast<GLsizei>(window_size.x),
             static_cast<GLsizei>(window_size.y));
}

inline void set_up_matrix_stack(const glm::vec2 &window_size, float pers_fovy,
                                float pers_near, float pers_far,
                                const glm::mat4 &view) {
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(
      glm::value_ptr(
          glm::perspective(pers_fovy, window_size.x / window_size.y, pers_near,
                           pers_far)));
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixf(glm::value_ptr(view));
}

inline bool set_up_lighting(unsigned int light, const glm::vec3 &ambient,
                            const glm::vec3 &diffuse, const glm::vec3 &specular,
                            const glm::vec3 &pos) {
  if (light >= GL_MAX_LIGHTS) {
    return false;
  }
  GLenum gl_light = GL_LIGHT0 + light;
  glLightfv(gl_light, GL_AMBIENT, glm::value_ptr(glm::vec4(ambient, 1.0f)));
  glLightfv(gl_light, GL_DIFFUSE, glm::value_ptr(glm::vec4(diffuse, 1.0f)));
  glLightfv(gl_light, GL_SPECULAR, glm::value_ptr(glm::vec4(specular, 1.0f)));
  glLightfv(gl_light, GL_POSITION, glm::value_ptr(glm::vec4(pos, 0.0f)));
  glEnable(gl_light);
  return true;
}

static inline void clean_up_lighting_impl(unsigned int light) {
  glDisable(GL_LIGHT0 + light);
}

inline bool clean_up_lighting(unsigned int light) {
  if (light >= GL_MAX_LIGHTS) {
    return false;
  }
  clean_up_lighting_impl(light);
  return true;
}

inline void clean_up_all_lighting() {
  for (int i = 0; i < GL_MAX_LIGHTS; ++i) {
    clean_up_lighting_impl(i);
  }
}

} /* namespace gl_cubic_rendering */

} /* namespace mojgame */


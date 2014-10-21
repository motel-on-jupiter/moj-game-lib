/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_GL_GLCUBICRENDERING_H_
#define MOJGAMELIB_AUXILIARY_GL_GLCUBICRENDERING_H_

#include "mojgame/includer/glm_include.h"

namespace mojgame {

namespace gl_cubic_rendering {

extern inline void set_up_viewport(const glm::vec2 &window_size);
extern inline void set_up_matrix_stack(const glm::vec2 &window_size,
                                       float pers_fovy, float pers_near,
                                       float pers_far, const glm::mat4 &view);

extern inline bool set_up_lighting(unsigned int light, const glm::vec3 &ambient,
                                   const glm::vec3 &diffuse,
                                   const glm::vec3 &specular,
                                   const glm::vec3 &pos);
extern inline bool clean_up_lighting(unsigned int light);
extern inline void clean_up_all_lighting();

extern inline void multi_model_matrix(const glm::vec3 &translation,
                                      const glm::quat &rotation,
                                      const glm::vec3 &scaling);

} /* namespace gl_cubic_rendering */

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_GL_GLCUBICRENDERING_H_ */

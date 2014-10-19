/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_GLMATERIALCOLOR_H_
#define MOJGAMELIB_AUXILIARY_GLMATERIALCOLOR_H_

#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

struct GLMaterialColor {
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float shininess;

  GLMaterialColor(const glm::vec3 &color)
      : ambient(color),
        diffuse(color),
        specular(glm::vec3(1.0f)),
        shininess(1.0f) {
  }
  GLMaterialColor(const glm::vec3 &ambient, const glm::vec3 &diffuse,
                  const glm::vec3 &specular, float shininess)
      : ambient(ambient),
        diffuse(diffuse),
        specular(specular),
        shininess(shininess) {
  }
};

extern inline void glMaterial(GLenum face,
                              const GLMaterialColor &material_color);

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_GLMATERIALCOLOR_H_ */

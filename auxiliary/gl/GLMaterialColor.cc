/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/gl/GLMaterialColor.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

void glMaterial(GLenum face, const GLMaterialColor &material_color) {
  glMaterialfv(face, GL_AMBIENT, glm::value_ptr(material_color.ambient));
  glMaterialfv(face, GL_DIFFUSE, glm::value_ptr(material_color.diffuse));
  glMaterialfv(face, GL_SPECULAR, glm::value_ptr(material_color.specular));
  glMaterialf(face, GL_SHININESS, material_color.shininess);
}

} /* namespace mojgame */

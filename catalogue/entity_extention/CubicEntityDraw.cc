/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/entity_extention/CubicEntityDraw.h"
#include "mojgame/auxiliary/glm_aux.h"
#include "mojgame/entity/CubicEntity.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

EntitySphereDraw::EntitySphereDraw(CubicEntity &entity, bool fill, int slices,
                                   int stacks,
                                   const GLMaterialColor &material_color)
    : CubicEntityDraw(entity, material_color),
      fill_(fill),
      slices_(slices),
      stacks_(stacks) {
}

void EntitySphereDraw::Draw() const {
  glColor3fv(glm::value_ptr(material_color().ambient));
  glMaterial(GL_FRONT, material_color());
  glPushMatrix();
  glMultMatrixf(
      glm::value_ptr(
          glm::translate(
              entity().pos() + glm_aux::y_dir() * entity().size() * 0.5f)
              * glm::toMat4(entity().rot()) * glm::scale(entity().size())));
  if (fill_) {
    glutSolidSphere(0.5, slices_, stacks_);
  } else {
    glutWireSphere(0.5, slices_, stacks_);
  }
  glPopMatrix();
}

EntityCubeDraw::EntityCubeDraw(CubicEntity &entity, bool fill,
                               const GLMaterialColor &material_color)
    : CubicEntityDraw(entity, material_color),
      fill_(fill) {
}

void EntityCubeDraw::Draw() const {
  glColor3fv(glm::value_ptr(material_color().ambient));
  glMaterial(GL_FRONT, material_color());
  glPushMatrix();
  glMultMatrixf(
      glm::value_ptr(
          glm::translate(
              entity().pos() + glm_aux::y_dir() * entity().size() * 0.5f)
              * glm::toMat4(entity().rot()) * glm::scale(entity().size())));
  if (fill_) {
    glutSolidCube(1.0);
  } else {
    glutWireCube(1.0);
  }
  glPopMatrix();
}

} /* namespace mojgame */


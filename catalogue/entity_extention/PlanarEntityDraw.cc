/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/entity_extention/PlanarEntityDraw.h"
#include "mojgame/auxiliary/gl/gl_aux.h"
#include "mojgame/entity/PlanarEntity.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

EntityPointDraw::EntityPointDraw(PlanarEntity &entity, const GLubyte *color)
    : PlanarEntityDraw(entity, color) {
}

void EntityPointDraw::Draw() const {
  if (color() != nullptr) {
    glColor3ubv(color());
  }
  glPointSize(entity().size().x);
  glBegin(GL_POINTS);
  glVertex2fv(glm::value_ptr(entity().pos()));
  glEnd();
}

EntityCircleDraw::EntityCircleDraw(PlanarEntity &entity, unsigned int splits,
                                   bool fill, const GLubyte *color)
    : PlanarEntityDraw(entity, color),
      splits_(splits),
      fill_(fill) {
}

void EntityCircleDraw::Draw() const {
  if (color() != nullptr) {
    glColor3ubv(color());
  }
  glPushMatrix();
  glMultMatrixf(
      glm::value_ptr(glm::translate(glm::vec3(entity().pos(), 0.0f))));
  glBegin(fill_ ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
  for (unsigned int i = 0; i < splits_; ++i) {
    float rot = entity().rot()
        + 2.0f * glm::pi<float>() * static_cast<float>(i)
            / static_cast<float>(splits_);
    glVertex2fv(
        glm::value_ptr(
            entity().size() * glm::vec2(0.5f * cos(rot), 0.5f * sin(rot))));
  }
  glEnd();
  glPopMatrix();
}

EntityTriangleDraw::EntityTriangleDraw(PlanarEntity &entity, bool fill,
                                       const GLubyte *color)
    : PlanarEntityDraw(entity, color),
      fill_(fill) {
}

void EntityTriangleDraw::Draw() const {
  if (color() != nullptr) {
    glColor3ubv(color());
  }
  glPushMatrix();
  glMultMatrixf(
      glm::value_ptr(glm::translate(glm::vec3(entity().pos(), 0.0f))));
  glBegin(fill_ ? GL_TRIANGLES : GL_LINE_LOOP);
  glVertex2fv(
      glm::value_ptr(
          glm::rotate(entity().size() * glm::vec2(0.0f, -0.5f),
                      entity().rot())));
  glVertex2fv(
      glm::value_ptr(
          glm::rotate(glm::vec2(entity().size() * glm::vec2(-0.5f, 0.5f)),
                      entity().rot())));
  glVertex2fv(
      glm::value_ptr(
          glm::rotate(glm::vec2(entity().size() * glm::vec2(0.5f, 0.5f)),
                      entity().rot())));
  glEnd();
  glPopMatrix();
}

EntityRectangleDraw::EntityRectangleDraw(PlanarEntity &entity, bool fill,
                                         const GLubyte *color)
    : PlanarEntityDraw(entity, color),
      fill_(fill) {
}

void EntityRectangleDraw::Draw() const {
  if (color() != nullptr) {
    glColor3ubv(color());
  }
  glPushMatrix();
  glMultMatrixf(
      glm::value_ptr(glm::translate(glm::vec3(entity().pos(), 0.0f)) *
                     glm::toMat4(glm_aux::angleAxisZ(entity().rot())) *
                     glm::scale(glm::vec3(entity().size(), 0.0f))));
  glBegin(fill_ ? GL_QUADS : GL_LINE_LOOP);
  glTexCoord2f(0.0f, 0.0f);
  glVertex2fv(glm::value_ptr(glm::vec2(-0.5f)));
  glTexCoord2f(0.0f, 1.0f);
  glVertex2fv(glm::value_ptr(glm::vec2(-0.5f, 0.5f)));
  glTexCoord2f(1.0f, 1.0f);
  glVertex2fv(glm::value_ptr(glm::vec2(0.5f)));
  glTexCoord2f(1.0f, 0.0f);
  glVertex2fv(glm::value_ptr(glm::vec2(0.5f, -0.5f)));
  glEnd();
  glPopMatrix();
}

EntityTextureDraw::EntityTextureDraw(PlanarEntity &entity, GLuint texname)
    : EntityRectangleDraw(entity, true, nullptr),
      texname_(texname) {
}

void EntityTextureDraw::Draw() const {
  if (0 != texname_) {
    glBindTexture(GL_TEXTURE_2D , texname_);
    EntityRectangleDraw::Draw();
  }
}

} /* namespace mojgame */

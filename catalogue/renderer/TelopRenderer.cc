/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/renderer/TelopRenderer.h"
#include "mojgame/includer/gl_include.h"

namespace mojgame {

bool GLTelopRenderer::OnRendering(const glm::vec2& window_size) {
  glPushMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(
      glm::value_ptr(glm::ortho(0.0f, window_size.x, window_size.y, 0.0f)));
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  const unsigned char *notice_message =
      reinterpret_cast<const unsigned char *>(telop_text_.c_str());
  glm::vec2 string_size = glm::vec2(
      glutBitmapLength(GLUT_BITMAP_9_BY_15, notice_message),
      glutBitmapHeight(GLUT_BITMAP_9_BY_15));
  glRasterPos2fv(glm::value_ptr(window_size * telop_pos_ - string_size * 0.5f));
  glutBitmapString(GLUT_BITMAP_9_BY_15, notice_message);
  glPopMatrix();
  return true;
}

} /* namespace mojgame */

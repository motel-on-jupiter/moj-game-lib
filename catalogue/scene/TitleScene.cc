/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/scene/TitleScene.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/scene/SceneRenderer.h"

namespace mojgame {

bool TitleSceneGLRenderer::OnRendering(const glm::vec2& window_size) {
  if (scene().time()
      - static_cast<float>(static_cast<int>(scene().time())) > 0.8f) {
    // for blinking
    return true;
  }
  glPushMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(
      glm::value_ptr(glm::ortho(0.0f, window_size.x, window_size.y, 0.0f)));
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  static const unsigned char *notice_message =
      reinterpret_cast<const unsigned char *>("PRESS ENTER KEY");
  glm::vec2 string_size = glm::vec2(
      glutBitmapLength(GLUT_BITMAP_9_BY_15, notice_message),
      glutBitmapHeight(GLUT_BITMAP_9_BY_15));
  glRasterPos2fv(glm::value_ptr(window_size * 0.5f - string_size * 0.5f));
  glutBitmapString(GLUT_BITMAP_9_BY_15, notice_message);
  glPopMatrix();
  return true;
}

} /* namespace mojgame */

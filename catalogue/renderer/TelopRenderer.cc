/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/renderer/TelopRenderer.h"
#include "mojgame/auxiliary/sdlttf_aux.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"
#include "mojgame/includer/sdlttf_include.h"

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
      reinterpret_cast<const unsigned char *>(telop_text().c_str());
  glm::vec2 string_size = glm::vec2(
      glutBitmapLength(GLUT_BITMAP_9_BY_15, notice_message),
      glutBitmapHeight(GLUT_BITMAP_9_BY_15));
  glRasterPos2fv(
      glm::value_ptr(window_size * telop_pos() - string_size * 0.5f));
  glutBitmapString(GLUT_BITMAP_9_BY_15, notice_message);
  glPopMatrix();
  return true;
}

#ifdef MOJGAMELIB_WITH_SDLTTF

bool GLTTFTelopRenderer::Initialize(TTF_Font *font) {
  if (font == nullptr) {
    mojgame::LOGGER().Error("font is nullptr");
    return false;
  }
  SDL_Color color;
  color.r = 0xff;
  color.g = 0xff;
  color.b = 0xff;
  color.a = 0xff;
  if (!text_.Initialize(font, telop_text().c_str(), color)) {
    mojgame::LOGGER().Error("Failed to initialize TTF text");
    return false;
  }
  set_initialized(true);
  return true;
}

void GLTTFTelopRenderer::Finalize() {
  text_.Finalize();
  set_initialized(false);
}

bool GLTTFTelopRenderer::OnRendering(const glm::vec2& window_size) {
  glPushMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(
      glm::value_ptr(glm::ortho(0.0f, window_size.x, window_size.y, 0.0f)));
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  text_.Render(window_size * telop_pos());
  glPopMatrix();
  return true;
}

#endif /* MOJGAMELIB_WITH_SDLTTF */

} /* namespace mojgame */

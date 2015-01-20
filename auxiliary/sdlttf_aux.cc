/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/sdlttf_aux.h"
#include "mojgame/includer/glm_include.h"
#include "mojgame/includer/sdl_include.h"
#include "mojgame/includer/sdlttf_include.h"

#ifdef MOJGAMELIB_WITH_SDLTTF

namespace mojgame {

bool GLTTFText::Initialize(TTF_Font *font, const char *text,
                           const SDL_Color& color) {
  if (initialized_) {
    return true;
  }
  surface_ = TTF_RenderText_Blended(font, text, color);
  if (surface_ == nullptr) {
    mojgame::LOGGER().Error("Failed to render text to surface");
    return false;
  }

  texname_ = 0;
  glGenTextures(1, &texname_);
  if (texname_ == 0) {
    mojgame::LOGGER().Error("Failed to generate texture");
    return false;
  }
  glBindTexture(GL_TEXTURE_2D, texname_);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface_->w, surface_->h, 0,
               GL_BGRA, GL_UNSIGNED_BYTE, surface_->pixels);
  return true;
}

void GLTTFText::Finalize() {
  if (initialized_) {
    glDeleteTextures(1, &texname_);
    SDL_FreeSurface(surface_);
    initialized_ = false;
  }
}

void GLTTFText::Render(const glm::vec2 &position, float scale) {
  if (initialized_) {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ASSERT(surface_ != nullptr);
    glm::vec2 text_size(surface_->w, surface_->h);
    text_size *= scale;

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2fv(glm::value_ptr(position + text_size * -0.5f));
    glTexCoord2f(1.0f, 0.0f);
    glVertex2fv(glm::value_ptr(position + text_size * glm::vec2(0.5f, -0.5f)));
    glTexCoord2f(1.0f, 1.0f);
    glVertex2fv(glm::value_ptr(position + text_size * 0.5f));
    glTexCoord2f(0.0f, 1.0f);
    glVertex2fv(glm::value_ptr(position + text_size * glm::vec2(-0.5f, 0.5f)));
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
  }
}

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_SDLTTF */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_RENDERER_TELOPRENDERER_H_
#define MOJGAMELIB_CATALOGUE_RENDERER_TELOPRENDERER_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/auxiliary/sdlttf_aux.h"
#include "mojgame/includer/glm_include.h"
#include "mojgame/includer/sdlttf_include.h"
#include "mojgame/renderer/Renderer.h"

namespace mojgame {

class TelopRenderer : public BaseRenderer {
 public:
  TelopRenderer()
      : telop_text_(""),
        telop_pos_(glm::vec2(0.5f)) {
  }
  TelopRenderer(const char *telop_text, const glm::vec2 &telop_pos)
      : telop_text_(telop_text),
        telop_pos_(telop_pos) {
  }
  ~TelopRenderer() {
  }

  void Reset(const char *telop_text, const glm::vec2 &telop_pos) {
    set_telop_text(telop_text);
    set_telop_pos(telop_pos);
  }

  void set_telop_text(const char *telop_text) {
    telop_text_.assign(telop_text);
  }
  void set_telop_pos(const glm::vec2 &telop_pos) {
    telop_pos_ = telop_pos;
  }
  const std::string &telop_text() const{
    return telop_text_;
  }
  const glm::vec2 & telop_pos() const {
    return telop_pos_;
  }

 private:
  std::string telop_text_;
  glm::vec2 telop_pos_;
};

class GLTelopRenderer : public TelopRenderer {
 public:
  GLTelopRenderer()
      : TelopRenderer() {
  }
  GLTelopRenderer(const char *telop_text, const glm::vec2 &telop_pos)
      : TelopRenderer(telop_text, telop_pos) {
  }
  ~GLTelopRenderer() {
  }
  bool Initialize() {
    set_initialized(true);
    return true;
  }
  void Finalize() {
    set_initialized(false);
  }

 protected:
  bool OnRendering(const glm::vec2 &window_size);
};

#ifdef MOJGAMELIB_WITH_SDLTTF

class GLTTFTelopRenderer : public TelopRenderer {
 public:
  GLTTFTelopRenderer()
      : TelopRenderer(),
        font_(nullptr),
        text_() {
  }
  GLTTFTelopRenderer(const char *telop_text, const glm::vec2 &telop_pos)
      : TelopRenderer(telop_text, telop_pos),
        font_(nullptr) {
  }
  ~GLTTFTelopRenderer() {
  }
  bool Initialize(TTF_Font *font);
  void Finalize();

 protected:
  bool OnRendering(const glm::vec2 &window_size);

 private:
  TTF_Font *font_;
  GLTTFText text_;
};

#endif /* MOJGAMELIB_WITH_SDLTTF */

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_RENDERER_TELOPRENDERER_H_ */

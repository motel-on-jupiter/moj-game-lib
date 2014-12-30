/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_RENDERER_TELOPRENDERER_H_
#define MOJGAMELIB_CATALOGUE_RENDERER_TELOPRENDERER_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/renderer/Renderer.h"

namespace mojgame {

class GLTelopRenderer : public BaseRenderer {
 public:
  GLTelopRenderer(const char *telop_text = "", const glm::vec2 &telop_pos =
                      glm::vec2(0.5f))
      : telop_text_(telop_text),
        telop_pos_(telop_pos) {
  }
  virtual ~GLTelopRenderer() {
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

 protected:
  virtual bool OnInitial(const glm::vec2 &window_size) {
    UNUSED(window_size);
    return true;
  }
  virtual void OnFinal() {
  }
  virtual bool OnRendering(const glm::vec2 &window_size);

 private:
  std::string telop_text_;
  glm::vec2 telop_pos_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_RENDERER_TELOPRENDERER_H_ */

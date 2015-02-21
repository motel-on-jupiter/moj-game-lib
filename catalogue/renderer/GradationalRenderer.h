/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAME_CATALOGUE_RENDERER_GRADATIONALRENDERER_H_
#define MOJGAME_CATALOGUE_RENDERER_GRADATIONALRENDERER_H_

#include <string>
#include "mojgame/renderer/Renderer.h"

namespace mojgame {

class GradationalGLRenderer : public BaseRenderer {
 public:
  GradationalGLRenderer(const char *gradation_vshader,
                        const char *gradation_fshader, int num_generations);
  virtual ~GradationalGLRenderer() {
  }
  bool Initialize(const glm::vec2 &window_size);
  void Finalize();

  mojgame::gl_shader::program_t gradation_program() {
    return gradation_program_;
  }
  void set_filling_level(float filling_level) {
    filling_level_ = filling_level;
  }

 protected:
  virtual bool OnRendering(const glm::vec2 &window_size);

 private:
  void RenderOnStege1();
  void RenderOnStege2();

  std::string gradation_vshader_;
  std::string gradation_fshader_;
  int num_generations_;
  mojgame::gl_shader::program_t gradation_program_;
  mojgame::gl_shader::program_t blit_program_;
  mojgame::GLFrameBuffer framebuf_;
  GLuint vertex_array_;
  GLuint vertex_buffer_;
  GLuint uv_buffer_;
  GLuint target_texname_;
  float filling_level_;
};

} /* namespace mojgame */

#endif /* MOJGAME_CATALOGUE_RENDERER_GRADATIONALRENDERER_H_ */

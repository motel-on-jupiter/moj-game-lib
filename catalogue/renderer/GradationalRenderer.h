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
  void set_filtering_r(float filtering_r) {
    filtering_r_ = filtering_r;
  }
  void set_filtering_g(float filtering_g) {
    filtering_g_ = filtering_g;
  }
  void set_filtering_b(float filtering_b) {
    filtering_b_ = filtering_b;
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
  float filtering_r_;
  float filtering_g_;
  float filtering_b_;
  float filling_level_;
};

} /* namespace mojgame */

#endif /* MOJGAME_CATALOGUE_RENDERER_GRADATIONALRENDERER_H_ */

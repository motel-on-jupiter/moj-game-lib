/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/catalogue/renderer/GradationalRenderer.h"
#include "mojgame/auxiliary/gl/gl_rendering.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/includer/gl_include.h"

#define SHADER_SOURCE(version, ...) "#version " #version "\n" #__VA_ARGS__

static const char kBlitVShaderSource[] = SHADER_SOURCE(330 core,
layout(location = 0) in vec2 coord;
layout(location = 1) in vec2 uv;

out vec2 vertexUv;

void main(void) {
  gl_Position.xy = coord;
  gl_Position.z = 0.0;
  gl_Position.w = 1.0;
  vertexUv = uv;
}
);

static const char kBlitFShaderSource[] = SHADER_SOURCE(330 core,
in vec2 vertexUv;

layout (location = 0) out vec4 fragmentColor;

uniform sampler2D texture;

void main(void) {
  fragmentColor = texture2D(texture, vertexUv);
  fragmentColor.rgb *= 5.0;
}
);

namespace mojgame {

GradationalGLRenderer::GradationalGLRenderer(const char *gradation_vshader,
                                             const char *gradation_fshader,
                                             int num_generations)
    : gradation_vshader_(gradation_vshader),
      gradation_fshader_(gradation_fshader),
      num_generations_(num_generations),
      gradation_program_(0),
      blit_program_(0),
      framebuf_(),
      vertex_array_(0),
      vertex_buffer_(0),
      uv_buffer_(0),
      target_texname_(0) {
}

bool GradationalGLRenderer::OnInitial(const glm::vec2 &window_size) {
  mojgame::gl_shader::program_t program;
  if (!mojgame::gl_shader::build_program(gradation_vshader_.c_str(),
                                         gradation_fshader_.c_str(),
                                         program)) {
    mojgame::LOGGER().Error("Failed to link gradation shader program");
    Finalize();
    return false;
  }
  gradation_program_ = program;
  if (!mojgame::gl_shader::build_program(kBlitVShaderSource, kBlitFShaderSource,
                                         program)) {
    mojgame::LOGGER().Error("Failed to link blit shader program");
    Finalize();
    return false;
  }
  blit_program_ = program;

  // Set up draw settings
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  // Set up frame buffer
  if (framebuf_.SetUp(window_size, num_generations_) < 0) {
    mojgame::LOGGER().Error("Failed to set up the frame buffer");
    return false;
  }
  for (auto it = framebuf_.colortexs().begin();
      it != framebuf_.colortexs().end(); ++it) {
    glBindTexture(GL_TEXTURE_2D, *it);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  }

  // Set up vertex objects for blooming
  glGenVertexArrays(1, &vertex_array_);
  glBindVertexArray(vertex_array_);
  glGenBuffers(1, &vertex_buffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  static const GLfloat kEffectCoords[] = { -1.0f, 1.0f, -1.0f, -1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, };
  glBufferData(GL_ARRAY_BUFFER, sizeof(kEffectCoords), kEffectCoords,
  GL_STATIC_DRAW);
  glGenBuffers(1, &uv_buffer_);
  glBindBuffer(GL_ARRAY_BUFFER, uv_buffer_);
  static const GLfloat kEffectUV[] = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
      1.0f };
  glBufferData(GL_ARRAY_BUFFER, sizeof(kEffectUV), kEffectUV, GL_STATIC_DRAW);
  return true;
}

void GradationalGLRenderer::OnFinal() {
  // Delete drawing objects
  glDeleteBuffers(1, &uv_buffer_);
  glDeleteBuffers(1, &vertex_buffer_);
  glDeleteVertexArrays(1, &vertex_array_);

  // Clean up frame buffer
  framebuf_.CleanUp();

  // Reset draw settings
  glDisable(GL_CULL_FACE);
  glUseProgram(0);
  mojgame::gl_shader::delete_program(gradation_program_);
  gradation_program_ = 0;
}

void GradationalGLRenderer::RenderOnStege1() {
  glUseProgram(gradation_program_);
  char symbol[] = "prev0_tex";
  for (int i = 0; i < num_generations_ - 1; ++i) {
    int bind = static_cast<int>(target_texname_) - i - 1;
    if (bind < 0) {
      bind += num_generations_;
    }
    mojgame::gl_rendering::bind_2d_texture(GL_TEXTURE0 + i, framebuf_.colortexs()[bind]);
    symbol[4] = '0' + static_cast<char>(i);
    mojgame::gl_shader::set_uniform_1i(gradation_program_, symbol, i);
  }

  mojgame::glBindDrawFramebuffer(framebuf_.name());
  mojgame::glFramebufferDrawColorAttachment(target_texname_);
  glDrawArrays(GL_QUADS, 0, 4);
}

void GradationalGLRenderer::RenderOnStege2() {
  glUseProgram(blit_program_);
  mojgame::gl_rendering::bind_2d_texture(
      GL_TEXTURE0, framebuf_.colortexs()[target_texname_]);
  mojgame::gl_shader::set_uniform_1i(blit_program_, "texture", 0);

  mojgame::glUnbindDrawFramebuffer();
  mojgame::gl_rendering::clear_color_buffer();
  glDrawArrays(GL_QUADS, 0, 4);
}

bool GradationalGLRenderer::OnRendering(const glm::vec2 &window_size) {
  UNUSED(window_size);

  /* Do common set-up */
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uv_buffer_);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  target_texname_ = (target_texname_ + 1) % num_generations_;

  /* Draw on steps */
  RenderOnStege1();
  RenderOnStege2();

  /* Do common clean-up */
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);
  return true;
}

} /* namespace mojgame */

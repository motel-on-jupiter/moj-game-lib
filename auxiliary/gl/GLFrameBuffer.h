/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAME_AUXILIARY_GL_GLFRAMEBUFFER_H_
#define MOJGAME_AUXILIARY_GL_GLFRAMEBUFFER_H_

#include <vector>
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

class GLFrameBuffer {
 public:
  GLFrameBuffer();
  virtual ~GLFrameBuffer();

  int SetUp(const glm::vec2 &window_size, int num_color_tex);
  void CleanUp();

  GLuint name() const {
    return name_;
  }
  GLuint renderbuf() const {
    return renderbuf_;
  }
  const std::vector<GLuint> &colortexs() const {
    return colortexs_;
  }
  GLuint depthtex() const {
    return depthtex_;
  }

 private:
  GLuint name_;
  GLuint renderbuf_;
  std::vector<GLuint> colortexs_;
  GLuint depthtex_;
};

} /* namespace mojgame */

#endif /* MOJGAME_AUXILIARY_GL_GLFRAMEBUFFER_H_ */

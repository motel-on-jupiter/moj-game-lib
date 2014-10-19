/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/gl/gl_aux.h"
#include <stddef.h>
#include "mojgame/auxiliary/assert_aux.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/logging/Logger.h"

namespace mojgame {

inline void glActiveTextureUnit(GLuint unit) {
  glActiveTexture(GL_TEXTURE0 + unit);
}

inline void glBindDrawFramebuffer(GLuint framebuffer) {
  glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
}

inline void glBindReadFramebuffer(GLuint framebuffer) {
  glBindFramebuffer(GL_READ_FRAMEBUFFER, framebuffer);
}

inline void glBindRenderbuffer_(GLuint renderbuffer) {
  glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
}

inline void glBindTexture1D(GLuint texture) {
  glBindTexture(GL_TEXTURE_1D, texture);
}

inline void glBindTexture2D(GLuint texture) {
  glBindTexture(GL_TEXTURE_2D, texture);
}

inline void glBindTexture3D(GLuint texture) {
  glBindTexture(GL_TEXTURE_3D, texture);
}

inline GLenum glCheckDrawFramebufferStatus() {
  return glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
}

inline GLenum glCheckReadFramebufferStatus() {
  return glCheckFramebufferStatus(GL_READ_FRAMEBUFFER);
}

inline void glDrawFramebufferColorTexture(GLint attachidx, GLuint texture,
                                          GLint level) {
  glFramebufferTexture(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachidx,
                       texture, level);
}

inline void glDrawFramebufferDepthTexture(GLuint texture, GLint level) {
  glFramebufferDepthTexture(GL_DRAW_FRAMEBUFFER, texture, level);
}

inline void glDrawFramebufferRenderbuffer(GLenum attachment,
                                          GLuint renderbuffer) {
  glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, attachment, GL_RENDERBUFFER,
                            renderbuffer);
}

inline void glFramebufferColorTexture(GLenum target, GLint attachidx,
                                      GLuint texture, GLint level) {
  ASSERT(attachidx < GL_MAX_COLOR_ATTACHMENTS);
  glFramebufferTexture(target, GL_COLOR_ATTACHMENT0 + attachidx, texture,
                       level);
}

inline void glFramebufferDepthTexture(GLenum target, GLuint texture,
                                      GLint level) {
  glFramebufferTexture(target, GL_DEPTH_ATTACHMENT, texture, level);
}

inline void glFramebufferDrawColorAttachment(GLint attachidx) {
  ASSERT(attachidx < GL_MAX_COLOR_ATTACHMENTS);
  glDrawBuffer(GL_COLOR_ATTACHMENT0 + attachidx);
}

inline void glGenFramebuffer(GLuint *id) {
  glGenFramebuffers(1, id);
}

inline void glGenRenderbuffer(GLuint *renderbuffer) {
  glGenRenderbuffers(1, renderbuffer);
}

inline void glGenTexture(GLuint *texture) {
  glGenTextures(1, texture);
}

inline void glReadFramebufferColorTexture(GLint attachidx, GLuint texture,
                                          GLint level) {
  glFramebufferTexture(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachidx,
                       texture, level);
}

inline void glReadFramebufferDepthTexture(GLuint texture, GLint level) {
  glFramebufferDepthTexture(GL_READ_FRAMEBUFFER, texture, level);
}

inline void glReadFramebufferRenderbuffer(GLenum attachment,
                                          GLuint renderbuffer) {
  glFramebufferRenderbuffer(GL_READ_FRAMEBUFFER, attachment, GL_RENDERBUFFER,
                            renderbuffer);
}

inline void glUnbindDrawFramebuffer() {
  glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

inline void glUnbindFramebuffer(GLenum target) {
  glBindFramebuffer(target, 0);
}

inline void glUnbindReadFramebuffer() {
  glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
}

} /* namespace mojgame */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_GLAUX_H_
#define MOJGAMELIB_AUXILIARY_GLAUX_H_

#include <vector>
#include "mojgame/includer/gl_include.h"

namespace mojgame {

extern int glCompileShaderFile(GLuint shader, const char *path);
extern int glLinkProgramWithShaders(GLuint program,
                                    std::vector<GLuint> &shaders);

extern inline void glActiveTextureUnit(GLuint unit);
extern inline void glBindDrawFramebuffer(GLuint framebuffer);
extern inline void glBindReadFramebuffer(GLuint framebuffer);
extern inline void glBindRenderbuffer_(GLuint renderbuffer);
extern inline void glBindTexture1D(GLuint texture);
extern inline void glBindTexture2D(GLuint texture);
extern inline void glBindTexture3D(GLuint texture);
extern inline GLenum glCheckDrawFramebufferStatus();
extern inline GLenum glCheckReadFramebufferStatus();
extern inline void glDrawFramebufferColorTexture(GLint attachidx,
                                                 GLuint texture, GLint level);
extern inline void glDrawFramebufferDepthTexture(GLuint texture, GLint level);
extern inline void glDrawFramebufferRenderbuffer(GLenum attachment,
                                                 GLuint renderbuffer);
extern inline void glFramebufferColorTexture(GLenum target, GLint attachidx,
                                             GLuint texture, GLint level);
extern inline void glFramebufferDepthTexture(GLenum target, GLuint texture,
                                             GLint level);
extern inline void glFramebufferDrawColorAttachment(GLint attachidx);
extern inline void glGenFramebuffer(GLuint *id);
extern inline void glGenRenderbuffer(GLuint *renderbuffer);
extern inline void glGenTexture(GLuint *texture);
extern inline void glReadFramebufferColorTexture(GLint attachidx,
                                                 GLuint texture, GLint level);
extern inline void glReadFramebufferDepthTexture(GLuint texture, GLint level);
extern inline void glReadFramebufferRenderbuffer(GLenum attachment,
                                                 GLuint renderbuffer);
extern inline void glUnbindDrawFramebuffer();
extern inline void glUnbindFramebuffer(GLenum target);
extern inline void glUnbindReadFramebuffer();

} /* namespace mojgame */

#include "mojgame/auxiliary/gl/GLFrameBuffer.h"
#include "mojgame/auxiliary/gl/GLMaterialColor.h"
#include "mojgame/auxiliary/gl/GLShader.h"

#endif /* MOJGAMELIB_AUXILIARY_GLAUX_H_ */

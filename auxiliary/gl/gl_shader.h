/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAME_AUXILIARY_GL_GLSHADER_H_
#define MOJGAME_AUXILIARY_GL_GLSHADER_H_

#include <vector>
#include "mojgame/includer/gl_include.h"

namespace mojgame {

namespace gl_shader {

typedef unsigned int shader_t;
extern inline bool compile_vshader(const char *source, shader_t &name);
extern inline bool compile_vshader_from_file(const char *path, shader_t &name);
extern inline bool compile_fshader(const char *source, shader_t &name);
extern inline bool compile_fshader_from_file(const char *path, shader_t &name);
extern inline void delete_shader(shader_t name);
extern inline void delete_shaders(std::vector<shader_t> names);

typedef unsigned int program_t;
extern inline bool link_program(shader_t vshader, shader_t fshader,
                                program_t &name);
extern inline void delete_program(program_t name);
extern inline void delete_programs(std::vector<program_t> names);
extern inline void set_uniform_f(program_t name, const char *uniform,
                                 float value);
extern inline void set_uniform_v2(program_t name, const char *uniform,
                                  const glm::vec2 &value);
extern inline void set_uniform_v3(program_t name, const char *uniform,
                                  const glm::vec3 &value);
extern inline void set_uniform_v4(program_t name, const char *uniform,
                                  const glm::vec4 &value);
extern inline void set_uniform_i(program_t name, const char *uniform,
                                 int value);
extern inline void set_uniform_iv2(program_t name, const char *uniform,
                                   const glm::ivec2 &value);

extern inline bool build_program(const char *vshader_source,
                                 const char *fshader_source, program_t &name);
extern inline bool build_program_from_file(const char *vshader_path,
                                           const char *fshader_path,
                                           program_t &name);

} /* namespace gl_shader */

} /* namespace mojgame */

#endif /* MOJGAME_AUXILIARY_GL_GLSHADER_H_ */

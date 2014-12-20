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

extern inline bool build_program(const char *vshader_source,
                                 const char *fshader_source, program_t &name);
extern inline bool build_program_from_file(const char *vshader_path,
                                           const char *fshader_path,
                                           program_t &name);

extern inline void set_uniform_f(program_t name, const char *uniform,
                                 float value);
extern inline void set_uniform_2f(program_t name, const char *uniform,
                                  const glm::vec2 &value);
extern inline void set_uniform_3f(program_t name, const char *uniform,
                                  const glm::vec3 &value);
extern inline void set_uniform_4f(program_t name, const char *uniform,
                                  const glm::vec4 &value);
extern inline void set_uniform_fv(program_t name, const char *uniform,
                                  const float *vector, int length);
extern inline void set_uniform_2fv(program_t name, const char *uniform,
                                   const float *vector, int length);
extern inline void set_uniform_3fv(program_t name, const char *uniform,
                                   const float *vector, int length);
extern inline void set_uniform_4fv(program_t name, const char *uniform,
                                   const float *vector, int length);
extern inline void set_uniform_1i(program_t name, const char *uniform,
                                  int value);
extern inline void set_uniform_2i(program_t name, const char *uniform,
                                  const glm::ivec2 &value);
extern inline void set_uniform_3i(program_t name, const char *uniform,
                                  const glm::ivec3 &value);
extern inline void set_uniform_4i(program_t name, const char *uniform,
                                  const glm::ivec4 &value);
extern inline void set_uniform_1iv(program_t name, const char *uniform,
                                   const int *vector, int length);
extern inline void set_uniform_2iv(program_t name, const char *uniform,
                                   const int *vector, int length);
extern inline void set_uniform_3iv(program_t name, const char *uniform,
                                   const int *vector, int length);
extern inline void set_uniform_4iv(program_t name, const char *uniform,
                                   const int *vector, int length);
extern inline void set_uniform_1ui(program_t name, const char *uniform,
                                   unsigned int value);
extern inline void set_uniform_2ui(program_t name, const char *uniform,
                                   const glm::uvec2 &value);
extern inline void set_uniform_3ui(program_t name, const char *uniform,
                                   const glm::uvec3 &value);
extern inline void set_uniform_4ui(program_t name, const char *uniform,
                                   const glm::uvec4 &value);
extern inline void set_uniform_1uiv(program_t name, const char *uniform,
                                    const unsigned int *vector, int length);
extern inline void set_uniform_2uiv(program_t name, const char *uniform,
                                    const unsigned int *vector, int length);
extern inline void set_uniform_3uiv(program_t name, const char *uniform,
                                    const unsigned int *vector, int length);
extern inline void set_uniform_4uiv(program_t name, const char *uniform,
                                    const unsigned int *vector, int length);

} /* namespace gl_shader */

} /* namespace mojgame */

#endif /* MOJGAME_AUXILIARY_GL_GLSHADER_H_ */

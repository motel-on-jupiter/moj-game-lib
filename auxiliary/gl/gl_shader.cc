/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/auxiliary/gl/gl_shader.h"
#include <errno.h>
#include <vector>
#include "mojgame/auxiliary/gl/gl_aux.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/logging/Logger.h"

namespace mojgame {

namespace gl_shader {

static inline bool compile_shader(const char *source, GLenum type,
                                  shader_t &name) {
  shader_t shader = glCreateShader(type);
  if (shader == 0) {
    LOGGER().Error("Failed to create shader (type: %d)", type);
    return false;
  }
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);
  GLint ok = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
  if (ok == GL_FALSE) {
    GLint loglen = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &loglen);
    char *log = new char[loglen];
    if (log == nullptr) {
      mojgame::LOGGER().Error(
          "Failed to compile shader and failed to allocate for log");
    } else {
      glGetShaderInfoLog(shader, loglen, nullptr, log);
      mojgame::LOGGER().Error("Failed to compile shader (errmsg: %s)", log);
      delete log;
    }
    delete_shader(shader);
    return false;
  }
  name = shader;
  return true;
}

static inline bool compile_shader_from_file(const char *path, GLenum type,
                                            shader_t &name) {
  FILE *fp = nullptr;
  if (fopen_s(&fp, path, "rb") != 0) {
    mojgame::LOGGER().Error("Failed to open shader file");
    return false;
  }
  if (fseek(fp, 0L, SEEK_END) != 0) {
    char errbuf[256];
    assert_equal(strerror_s(errbuf, ARRAYSIZE(errbuf), errno), 0);
    mojgame::LOGGER().Error("Failed to seek the end of file (errmsg: %s)",
                            errbuf);
  }
  long filesize = ftell(fp);
  if (fseek(fp, 0L, SEEK_SET) != 0) {
    char errbuf[256];
    assert_equal(strerror_s(errbuf, ARRAYSIZE(errbuf), errno), 0);
    mojgame::LOGGER().Error("Failed to seek the start of file (errmsg: %s)",
                            errbuf);
  }
  GLchar *source = new char[filesize / sizeof(char) + 1];
  if (source == nullptr) {
    mojgame::LOGGER().Error("Failed to allocate source buffer");
    return false;
  }
  do {
    fread(source, 1, filesize, fp);
  } while (errno == EINVAL);
  fclose(fp);
  source[filesize] = '\0';

  bool status = compile_shader(source, type, name);
  delete source;
  return status;
}

inline bool compile_vshader(const char *source, shader_t &name) {
  return compile_shader(source, GL_VERTEX_SHADER, name);
}

inline bool compile_vshader_from_file(const char *path, shader_t &shader) {
  return compile_shader_from_file(path, GL_VERTEX_SHADER, shader);
}

inline bool compile_fshader(const char *source, shader_t &name) {
  return compile_shader(source, GL_FRAGMENT_SHADER, name);
}

inline bool compile_fshader_from_file(const char *path, shader_t &shader) {
  return compile_shader_from_file(path, GL_FRAGMENT_SHADER, shader);
}

inline void delete_shader(shader_t name) {
  glDeleteShader(name);
}

inline void delete_shaders(std::vector<shader_t> names) {
  for (auto it = names.begin(); it != names.end(); ++it) {
    delete_shader(*it);
  }
}

inline bool link_program(shader_t vshader, shader_t fshader, program_t &name) {
  program_t program = glCreateProgram();
  if (program == 0) {
    LOGGER().Error("Failed to create program");
    return false;
  }
  glAttachShader(program, vshader);
  glAttachShader(program, fshader);
  glLinkProgram(program);
  GLint ok = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &ok);
  if (ok == GL_FALSE) {
    GLint loglen = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &loglen);
    char *log = new char[loglen];
    if (log == nullptr) {
      mojgame::LOGGER().Error(
          "Failed to link program and failed to allocate for log");
    } else {
      glGetProgramInfoLog(program, loglen, nullptr, log);
      mojgame::LOGGER().Error("Failed to link program (errmsg: %s)", log);
      free(log);
    }
    delete_program(program);
    return false;
  }
  name = program;
  return true;
}

inline void delete_program(program_t name) {
  glDeleteProgram(name);
}

inline void delete_programs(std::vector<program_t> names) {
  for (auto it = names.begin(); it != names.end(); ++it) {
    delete_program(*it);
  }
}

inline void set_uniform_f(program_t name, const char *uniform, float value) {
  glUniform1f(glGetUniformLocation(name, uniform), value);
}

inline void set_uniform_v2(program_t name, const char *uniform,
                           const glm::vec2 &value) {
  glUniform2fv(glGetUniformLocation(name, uniform), 1, glm::value_ptr(value));
}

inline void set_uniform_v3(program_t name, const char *uniform,
                           const glm::vec3 &value) {
  glUniform3fv(glGetUniformLocation(name, uniform), 1, glm::value_ptr(value));
}

inline void set_uniform_v4(program_t name, const char *uniform,
                           const glm::vec4 &value) {
  glUniform4fv(glGetUniformLocation(name, uniform), 1, glm::value_ptr(value));
}

inline void set_uniform_i(program_t name, const GLchar *uniform, int value) {
  glUniform1i(glGetUniformLocation(name, uniform), value);
}

inline void set_uniform_iv2(program_t name, const char *uniform,
                            const glm::ivec2 &value) {
  glUniform2iv(glGetUniformLocation(name, uniform), 1, glm::value_ptr(value));
}

inline bool build_program(const char *vshader_source,
                          const char *fshader_source, program_t &name) {
  shader_t vshader, fshader;
  return compile_vshader(vshader_source, vshader)
      && compile_fshader(fshader_source, fshader)
      && link_program(vshader, fshader, name);
}

inline bool build_program_from_file(const char *vshader_path,
                                    const char *fshader_path,
                                    program_t &name) {
  shader_t vshader, fshader;
  return compile_vshader_from_file(vshader_path, vshader)
      && compile_fshader_from_file(fshader_path, fshader)
      && link_program(vshader, fshader, name);
}

} /* namespace gl_shader */

} /* namespace mojgame */

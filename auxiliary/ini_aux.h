/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_INIAUX_H_
#define MOJGAMELIB_AUXILIARY_INIAUX_H_

#include <string>
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/includer/glm_include.h"
#include "mojgame/includer/ini_include.h"

namespace mojgame {

class INIReadable : public NonCopyable<INIReadable> {
 public:
  INIReadable(INIReader &reader)
     : reader_(reader) {
  }

  INIReader &reader() { return reader_; }

 private:
  INIReader &reader_;
};

class INIReadableForGL : public INIReadable {
 public:
  INIReadableForGL(INIReader &reader)
      : INIReadable(reader) {
  }

  GLfloat GetGLFloating(std::string section, std::string name,
                        float default_value);
};

class INIReadableForGLM : public INIReadable {
 public:
  INIReadableForGLM(INIReader &reader)
      : INIReadable(reader) {
  }

  glm::vec2 GetVector2(std::string section, std::string name,
                       glm::vec2 default_value);
  glm::vec3 GetVector3(std::string section, std::string name,
                       glm::vec3 default_value);
  glm::vec4 GetVector4(std::string section, std::string name,
                       glm::vec4 default_value);
  glm::i32vec2 GetIntVector2(std::string section, std::string name,
                             glm::i32vec2 default_value);
  glm::i32vec3 GetIntVector3(std::string section, std::string name,
                             glm::i32vec3 default_value);
  glm::i32vec4 GetIntVector4(std::string section, std::string name,
                             glm::i32vec4 default_value);
};

} /* namespace mojgame */

#endif  /* MOJGAMELIB_AUXILIARY_INIAUX_H_ */

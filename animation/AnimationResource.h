/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_ANIMATION_ANIMATIONRESOURCE_H_
#define MOJGAMELIB_ANIMATION_ANIMATIONRESOURCE_H_

#include <vector>
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/sdl_include.h"

namespace mojgame {

class AnimationResource {
 public:
  AnimationResource(const char **texpaths);
  virtual ~AnimationResource() {
  }

  bool Load();
  void Unload();

  GLuint texname(int resource_id) const {
    return texnames_[resource_id];
  }

 private:
  const char **texpaths_;
  std::vector<SDL_Surface *> surfaces_;
  std::vector<GLuint> texnames_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ANIMATION_ANIMATIONRESOURCE_H_ */

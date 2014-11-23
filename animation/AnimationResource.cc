/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/animation/AnimationResource.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/sdl_include.h"
#include "mojgame/includer/sdlimage_include.h"

namespace mojgame {

AnimationResource::AnimationResource(
    const char **texpaths)
    : texpaths_(texpaths),
      texnames_() {
}

bool AnimationResource::Load() {
  bool status = true;
  for (int i = 0; texpaths_[i] != nullptr; ++i) {
    const char *texpath = texpaths_[i];
    if (texpath == nullptr) {
      surfaces_.push_back(nullptr);
      texnames_.push_back(0);
      continue;
    }

    SDL_Surface *surface = IMG_Load(texpath);
    if (nullptr == surface) {
      mojgame::LOGGER().Error(
          "Failed to load texture image (path: %s, errmsg: %s)", texpath,
          IMG_GetError());
      surfaces_.push_back(nullptr);
      texnames_.push_back(0);
      status = false;
      continue;
    }
    surfaces_.push_back(surface);

    GLuint texname;
    glGenTextures(1, &texname);
    glBindTexture(GL_TEXTURE_2D, texname);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, surface->w, surface->h, 0, GL_RGBA,
    GL_UNSIGNED_BYTE,
                 surface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texnames_.push_back(texname);
  }
  return status;
}

void AnimationResource::Unload() {
  for (auto it = texnames_.begin(); it != texnames_.end(); ++it) {
    glDeleteTextures(1, &(*it));
  }
  texnames_.clear();
  for (auto it = surfaces_.begin(); it != surfaces_.end(); ++it) {
    SDL_FreeSurface(*it);
  }
  surfaces_.clear();
}

} /* namespace mojgame */

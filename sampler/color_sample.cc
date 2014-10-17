/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/sampler/color_sample.h"

namespace mojgame {

namespace WebColor {
glm::vec3 to_fvec(const unsigned char (&color)[3]) {
  return glm::vec3(static_cast<float>(color[0]), static_cast<float>(color[1]),
                   static_cast<float>(color[2])) / glm::vec3(255.0f);
}
}

namespace X11Color {
glm::vec3 to_fvec(const unsigned char (&color)[3]) {
  return glm::vec3(static_cast<float>(color[0]), static_cast<float>(color[1]),
                   static_cast<float>(color[2])) / glm::vec3(255.0f);
}
}

} /* namespace mojgame */

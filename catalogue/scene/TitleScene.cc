/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/catalogue/scene/TitleScene.h"
#include "mojgame/includer/gl_include.h"

namespace mojgame {

bool GLTitleScene::OnRendering(const glm::vec2& window_size) {
  if (time() - static_cast<float>(static_cast<int>(time())) > 0.8f) {
    // for blinking
    return true;
  }
  return renderer_.Render(window_size);
}

} /* namespace mojgame */

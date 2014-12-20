/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/scene/SceneGraph.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/logging/Logger.h"
#include "mojgame/scene/Scene.h"

namespace mojgame {

bool SceneGraphIterator::Initiaize(const glm::vec2 &window_size) {
  return NextImpl(nullptr, -1, window_size);
}

void SceneGraphIterator::Finalize() {
  CleanCurrent();
}

bool SceneGraphIterator::Next(int condition, const glm::vec2 &window_size) {
  BaseScene *previous = current_;
  CleanCurrent();
  return NextImpl(previous, condition, window_size);
}

void SceneGraphIterator::CleanCurrent() {
  if (current_ != nullptr) {
    current_->Finalize();
  }
  current_ = nullptr;
}

bool SceneGraphIterator::NextImpl(BaseScene *previous, int condition,
                                  const glm::vec2 &window_size) {
  for (auto it = graph_.begin(); it != graph_.end(); ++it) {
    SceneFlow flow = (*it).first;
    if ((flow.first == previous)
        && ((condition < 0) || ((*it).second == condition))) {
      BaseScene *next = flow.second;
      if (next == nullptr) {
        mojgame::LOGGER().Warn("Ignored the invalid scene flow whose end is null");
        continue;
      }
      int ret = next->Initialize(window_size);
      if (ret < 0) {
        mojgame::LOGGER().Error("Failed to initialize the scene (scene: %s, error: %d)",
                     next->name().c_str(), ret);
        return false;
      }
      current_ = next;
    }
  }
  return true;
}

} /* namespace mojgame */

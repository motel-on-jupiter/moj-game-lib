/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/scene/GraphDrivenScene.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/logging/Logger.h"

namespace mojgame {

GraphDrivenScene::GraphDrivenScene(const char *name, const SceneGraph &graph)
    : BaseScene(name),
      graph_iter_(graph) {
}

GraphDrivenScene::~GraphDrivenScene() {
}

bool GraphDrivenScene::OnInitial() {
  if (!graph_iter_.Initiaize()) {
    mojgame::LOGGER().Error("Failed to initialize graph iterator");
    return false;
  }
  return true;
}

void GraphDrivenScene::OnFinal() {
  graph_iter_.Finalize();
}

bool GraphDrivenScene::OnStep(float elapsed_time) {
  if (graph_iter_.current() != nullptr) {
    if (!graph_iter_.current()->Step(elapsed_time)) {
      mojgame::LOGGER().Error("Failed to next the scene graph iterator");
      return false;
    }
    if (graph_iter_.current()->finished()) {
      std::string prev_name = graph_iter_.current()->name();
      if (graph_iter_.Next(0)) {
        if (graph_iter_.current() == nullptr) {
          mojgame::LOGGER().Info("Shift the scene (prev: %s, next: %s)", prev_name.c_str(),
                                 SAFE_STR(graph_iter_.current()->name().c_str()));
        }
      } else {
        mojgame::LOGGER().Error("Failed to next the scene graph iterator");
        return false;
      }
    }
  }
  return true;
}

} /* namespace mojgame */

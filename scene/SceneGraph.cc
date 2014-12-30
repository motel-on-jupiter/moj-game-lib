/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/scene/SceneGraph.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/logging/Logger.h"
#include "mojgame/scene/Scene.h"

namespace mojgame {

void SceneGraph::InsertAsRoot(BaseScene *root) {
  assert_nonnull(root);
  edges_.push_back(SceneEdge(nullptr, root));
}

void SceneGraph::Insert(BaseScene *src, BaseScene *dst) {
  assert_nonnull(src);
  assert_nonnull(dst);
  edges_.push_back(SceneEdge(src, dst));
}

void SceneGraph::InsertAsLeaf(BaseScene *leaf) {
  assert_nonnull(leaf);
  edges_.push_back(SceneEdge(leaf, nullptr));
}

void SceneGraph::Trace(BaseScene *src, Scenes &dsts, bool null_removal) const {
  dsts.clear();
  for (auto it = edges_.begin(); it != edges_.end(); ++it) {
    if (it->src == src) {
      if (null_removal && it->dst == nullptr) {
        continue;
      }
      dsts.push_back(it->dst);
    }
  }
}

void SceneGraph::Clear() {
  edges_.clear();
}

bool SceneGraphIterator::Next(const glm::vec2 &window_size) {
  SceneGraph::Scenes candidates;
  graph_.Trace(current_, candidates);
  BaseScene *next_scene = nullptr;
  if (candidates.size() == 0) {
    mojgame::LOGGER().Warn("No linked edge found");
  } else if (candidates.size() == 1) {
    next_scene = candidates.front();
  } else {
    SceneGraph::Scenes::iterator next;
    if (!graph_.OnChoice(current_, candidates.begin(), candidates.end(), next)) {
      mojgame::LOGGER().Error("Failed to choise the next scene (current: %s)",
                              current_->name().c_str());
      return false;
    }
    next_scene = *next;
  }
  if (next_scene != nullptr) {
    if (!next_scene->Initialize(window_size)) {
      mojgame::LOGGER().Error(
          "Failed to initialize the next scene (current: %s, next: %s)",
          (current_ == nullptr) ? "none" : current_->name().c_str(),
          next_scene->name().c_str());
      return false;
    }
  }
  if (current_ != nullptr) {
    current_->Finalize();
  }
  current_ = next_scene;
  return true;
}

void SceneGraphIterator::Clean() {
  if (current_ != nullptr) {
    current_->Finalize();
  }
  current_ = nullptr;
}

} /* namespace mojgame */

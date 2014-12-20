/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_SCENE_SCENEGRAPH_H_
#define MOJGAMELIB_SCENE_SCENEGRAPH_H_

#include <utility>
#include <vector>
#include "mojgame/auxiliary/csyntax_aux.h"

namespace mojgame {

class BaseScene;

typedef std::pair<BaseScene *, BaseScene *> SceneFlow;
typedef std::pair<SceneFlow, int> SceneEdge;
typedef std::vector<SceneEdge> SceneGraph;

class SceneGraphIterator : public NonCopyable<SceneGraphIterator> {
 public:
  SceneGraphIterator(const SceneGraph &graph)
      : graph_(graph),
        current_(nullptr) {
  }
  virtual ~SceneGraphIterator() {
  }

  bool Initiaize(const glm::vec2 &window_size);
  void Finalize();
  bool Next(int condition, const glm::vec2 &window_size);

  const SceneGraph &graph() const {
    return graph_;
  }
  BaseScene *current() {
    return current_;
  }

 private:
  void CleanCurrent();
  bool NextImpl(BaseScene *previous, int condition,
                const glm::vec2 &window_size);

  const SceneGraph &graph_;
  BaseScene *current_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_SCENEGRAPH_H_ */

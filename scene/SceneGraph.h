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

struct SceneEdge {
  BaseScene *src;
  BaseScene *dst;

  SceneEdge(BaseScene *src, BaseScene *dst)
      : src(src),
        dst(dst) {
  }
};

class SceneGraph {
 public:
  typedef std::vector<mojgame::BaseScene *> Scenes;

  SceneGraph()
      : edges_() {
  }
  virtual ~SceneGraph() {
  }

  void InsertAsRoot(BaseScene *root);
  void Insert(BaseScene *src, BaseScene *dst);
  void InsertAsLeaf(BaseScene *leaf);
  void Trace(BaseScene *src, Scenes &dsts, bool null_removal=false) const;
  void Clear();

  virtual bool OnChoice(mojgame::BaseScene *current, Scenes::iterator candidates_begin,
                        Scenes::iterator candidates_end, Scenes::iterator &next) const = 0;

  const std::vector<SceneEdge> &edges() const {
    return edges_;
  }

 private:
  std::vector<SceneEdge> edges_;
};

class SceneGraphIterator : public NonCopyable<SceneGraphIterator> {
 public:
  SceneGraphIterator(const SceneGraph &graph)
      : graph_(graph),
        current_(nullptr) {
  }
  virtual ~SceneGraphIterator() {
  }

  bool Next(const glm::vec2 &window_size);
  void Clean();

  const SceneGraph &graph() const {
    return graph_;
  }
  BaseScene *current() {
    return current_;
  }

 private:
  const SceneGraph &graph_;
  BaseScene *current_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_SCENEGRAPH_H_ */

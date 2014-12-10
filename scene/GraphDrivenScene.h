/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_SCENE_GRAPHDRIVENSCENE_H_
#define MOJGAMELIB_SCENE_GRAPHDRIVENSCENE_H_

#include "mojgame/scene/Scene.h"
#include "mojgame/scene/SceneGraph.h"

namespace mojgame {

class GraphDrivenScene : public BaseScene {
 public:
  GraphDrivenScene(const char *name, const SceneGraph &graph);
  virtual ~GraphDrivenScene();

 protected:
  virtual bool OnInitial();
  virtual void OnFinal();
  virtual bool OnStep(float elapsed_time);

  SceneGraphIterator graph_iter_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_SCENE_GRAPHDRIVENSCENE_H_ */

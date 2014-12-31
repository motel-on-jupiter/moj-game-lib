/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_ENTITY_ACTOR_H_
#define MOJGAMELIB_ENTITY_ACTOR_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/entity/PlanarEntity.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

class PlanarActor : public mojgame::PlanarEntity {
 public:
  PlanarActor(float speed)
      : mojgame::PlanarEntity(glm::vec2(), 0.0f, glm::vec2()),
        walk_speed_(speed),
        appeared_(false),
        walking_(false),
        walk_dst_() {
  }
  virtual ~PlanarActor() {
  }

  bool Step(float elapsed_time);
  void Appear(const glm::vec2 &pos, float rot, const glm::vec2 &size);
  void Disappear();
  void Walk(const glm::vec2 &dst);

  bool appeared() const {
    return appeared_;
  }
  bool walking() const {
    return walking_;
  }

 protected:
  virtual bool OnStep(float elapsed_time) {
    UNUSED(elapsed_time);
    return true;
  }

 private:
  float walk_speed_;
  bool appeared_;
  bool walking_;
  glm::vec2 walk_dst_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ENTITY_ACTOR_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_ENTITYEXTENTION_CUBICENTITYPHYSICS_H_
#define MOJGAMELIB_CATALOGUE_ENTITYEXTENTION_CUBICENTITYPHYSICS_H_

#ifdef MOJGAMELIB_WITH_BULLET

#include "mojgame/auxiliary/glm_aux.h"
#include "mojgame/entity/CubicEntity.h"
#include "mojgame/includer/bullet_include.h"

namespace mojgame {

class CubicEntityMotionState : public btMotionState, public NonCopyable<
    CubicEntityMotionState> {
 public:
  CubicEntityMotionState(CubicEntity &entity)
      : entity_(entity) {
  }
  virtual ~CubicEntityMotionState() {
  }

  virtual void getWorldTransform(btTransform& worldTrans) const {
    worldTrans.setOrigin(
        glm_aux::toBtVec3(
            entity_.pos() + glm_aux::y_dir() * entity_.size() * 0.5f));
    worldTrans.setRotation(glm_aux::toBtQuat(entity_.rot()));
  }
  virtual void setWorldTransform(const btTransform& worldTrans) {
    entity_.MoveTo(
        glm_aux::fromBtVec3(worldTrans.getOrigin())
            - glm_aux::y_dir() * entity_.size() * 0.5f);
    entity_.RotateTo(glm_aux::fromBtQuat(worldTrans.getRotation()));
  }

 private:
  CubicEntity &entity_;
};

class CubicEntityPhysics : public CubicEntityExtention {
 public:
  CubicEntityPhysics(CubicEntity &entity)
      : CubicEntityExtention(entity),
        bt_motion_(nullptr),
        bt_body_(nullptr) {
  }
  virtual ~CubicEntityPhysics() {
    CleanObjects();
  }

  virtual bool Initialize(btScalar mass, btCollisionShape &shape,
                          btScalar restitution);
  virtual void Finalize();

  virtual void SetVelocity(const glm::vec3 &velocity) {
    bt_body()->setLinearVelocity(glm_aux::toBtVec3(velocity));
  }
  virtual void SetAngularVelocity(const glm::vec3 &velocity) {
    bt_body()->setAngularVelocity(glm_aux::toBtVec3(velocity));
  }
  virtual void SetAngularVelocity(const glm::quat &rotation) {
    bt_body()->setAngularVelocity(
        btVector3(glm::pitch(rotation), glm::yaw(rotation),
                  glm::roll(rotation)));
  }

  btRigidBody *bt_body() {
    return bt_body_;
  }

 private:
  void CleanObjects();

  btMotionState *bt_motion_;
  btRigidBody *bt_body_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_BULLET */

#endif /* MOJGAMELIB_CATALOGUE_ENTITYEXTENTION_CUBICENTITYPHYSICS_H_ */

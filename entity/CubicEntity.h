/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_ENTITY_CUBICENTITY_H_
#define MOJGAMELIB_ENTITY_CUBICENTITY_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

class CubicEntity {
 public:
  CubicEntity(const glm::vec3 &size)
      : pos_(glm::vec3()),
        rot_(glm::quat()),
        size_(size) {
  }
  CubicEntity(const glm::vec3 &pos, const glm::quat &rot, const glm::vec3 &size)
      : pos_(pos),
        rot_(rot),
        size_(size) {
  }
  virtual ~CubicEntity() {
  }

  void Move(const glm::vec3 &offset) {
    set_pos(pos() + offset);
  }
  void MoveTo(const glm::vec3 &pos) {
    set_pos(pos);
  }
  void Rotate(const glm::quat &offset) {
    set_rot(offset * rot());
  }
  void RotateTo(const glm::quat &rot) {
    set_rot(rot);
  }
  void Resize(const glm::vec3 &offset) {
    set_size(size() * offset);
  }
  void ResizeTo(const glm::vec3 &size) {
    set_size(size);
  }

  const glm::vec3 &pos() const {
    return pos_;
  }
  void set_pos(const glm::vec3 &pos) {
    pos_ = pos;
  }
  const glm::quat &rot() const {
    return rot_;
  }
  void set_rot(const glm::quat &rot) {
    rot_ = rot;
  }
  const glm::vec3 &size() const {
    return size_;
  }
  void set_size(const glm::vec3 &size) {
    size_ = size;
  }

  const glm::mat4 &BuildTransformMatrix() const {
    return glm::translate(pos_) * glm::toMat4(rot_) * glm::scale(size_);
  }

 private:
  glm::vec3 pos_;
  glm::quat rot_;
  glm::vec3 size_;
};

class CubicEntityExtention : public NonCopyable<CubicEntityExtention> {
 public:
  explicit CubicEntityExtention(CubicEntity &entity)
      : entity_(entity) {
  }
  virtual ~CubicEntityExtention() {
  }

 protected:
  CubicEntity &entity() {
    return entity_;
  }
  const CubicEntity &entity() const {
    return entity_;
  }

 private:
  CubicEntity &entity_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ENTITY_CUBICENTITY_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_ENTITY_PLANARENTITY_H_
#define MOJGAMELIB_ENTITY_PLANARENTITY_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/auxiliary/glm_aux.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

class PlanarEntity {
 public:
  PlanarEntity(const glm::vec2 &pos, float rot, const glm::vec2 &size)
      : pos_(pos),
        rot_(rot),
        size_(size) {
  }
  virtual ~PlanarEntity() {
  }

  void Move(const glm::vec2 &offset) {
    set_pos(pos() + offset);
  }
  void MoveTo(const glm::vec2 &pos) {
    set_pos(pos);
  }
  void Rotate(float offset) {
    set_rot(glm_aux::normalizeAngle(rot() + offset));
  }
  void RotateTo(float rot) {
    set_rot(glm_aux::normalizeAngle(rot));
  }
  void Resize(const glm::vec2 &offset) {
    set_size(size() * offset);
  }
  void ResizeTo(const glm::vec2 &size) {
    set_size(size);
  }

  glm::vec2 pos() const {
    return pos_;
  }
  void set_pos(const glm::vec2 &pos) {
    pos_ = pos;
  }
  float rot() const {
    return rot_;
  }
  void set_rot(float rot) {
    rot_ = rot;
  }
  glm::vec2 size() const {
    return size_;
  }
  void set_size(const glm::vec2 &size) {
    size_ = size;
  }

 private:
  glm::vec2 pos_;
  float rot_;
  glm::vec2 size_;
};

class PlanarEntityExtention : public NonCopyable<PlanarEntityExtention> {
 public:
  explicit PlanarEntityExtention(PlanarEntity &entity)
      : entity_(entity) {
  }
  virtual ~PlanarEntityExtention() {
  }

 protected:
  PlanarEntity &entity() {
    return entity_;
  }
  const PlanarEntity &entity() const {
    return entity_;
  }

 private:
  PlanarEntity &entity_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_ENTITY_PLANARENTITY_H_ */

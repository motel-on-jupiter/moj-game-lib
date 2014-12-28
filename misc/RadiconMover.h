/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_MISC_RADICONMOVER_H_
#define MOJGAMELIB_MISC_RADICONMOVER_H_

namespace mojgame {

class RadiconMover {
 public:
  RadiconMover()
      : pos_(),
        dir_(0.0f),
        speed_(0.0f) {
  }
  ~RadiconMover() {
  }

  void Reset(const glm::vec2 &pos, float dir, float speed = 0.0f) {
    pos_ = pos;
    dir_ = dir;
    speed_ = speed;
  }
  void Move(float speed_scale = 1.0f) {
    pos_ += glm::vec2(glm::cos(dir_), glm::sin(dir_)) * speed_ * speed_scale;
  }
  void Rotate(float rot) {
    dir_ += rot;
  }
  void Accel(float accel) {
    speed_ += accel;
  }
  void Brake(float brake) {
    if (math_aux::is_fpositive(brake)) {
      if (glm::abs(speed_) < brake) {
        speed_ = 0.0f;
      } else {
        speed_ = (glm::abs(speed_) - brake) * math_aux::sign(speed_);
      }
    }
  }

  const glm::vec2 &pos() const {
    return pos_;
  }
  float dir() {
    return dir_;
  }
  float speed() {
    return speed_;
  }
  void set_pos(const glm::vec2 &pos) {
    pos_ = pos;
  }
  void set_dir(float dir) {
    dir_ = dir;
  }
  void set_speed(float speed) {
    speed_ = speed;
  }

 private:
  glm::vec2 pos_;
  float dir_;
  float speed_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_MISC_RADICONMOVER_H_ */

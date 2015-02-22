/**
 * Copyright (C) 2015 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUDIO_SEPLAYER_H_
#define MOJGAMELIB_AUDIO_SEPLAYER_H_

#include "mojgame/includer/al_include.h"

#ifdef MOJGAMELIB_WITH_ALURE

namespace mojgame {

class AlureSe {
 public:
  AlureSe(const char *se_file_path, unsigned int source_slot_length);
  ~AlureSe() {
  }

  bool Initialize(float pitch, float gain);
  void Finalize();

  const std::string &se_file_path() const {
    return se_file_path_;
  }

  int RotateSlot() {
    active_slot_ = (active_slot_ + 1) % slot_length_;
    return active_slot_;
  }
  ALuint GetSource(unsigned int slot_idx) const {
    if (source_slot_ == nullptr) {
      return 0;
    }
    if (slot_idx >= slot_length_) {
      return 0;
    }
    return source_slot_[slot_idx];
  }

 private:
  std::string se_file_path_;
  unsigned int slot_length_;
  unsigned int active_slot_;
  ALuint *source_slot_;
  ALuint buffer_;
};

namespace AlureSePlayer {
  int Play(AlureSe &se, const glm::vec3 &pos = glm::vec3(),
           float pitch = -1.0f, float gain = -1.0f);
  bool Stop(AlureSe &se, int slot_idx);
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_ALURE */

#endif /* MOJGAMELIB_AUDIO_SEPLAYER_H_ */

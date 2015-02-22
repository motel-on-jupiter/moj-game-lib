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
  AlureSe(const char *se_file_path);
  ~AlureSe() {
  }

  bool Initialize(float pitch, float gain);
  void Finalize();

  void ChangePitch(float pitch);
  void ChangeGain(float gain);

  const std::string &se_file_path() const {
    return se_file_path_;
  }
  ALuint source() const {
    return source_;
  }
  ALuint buffer() const {
    return buffer_;
  }

 private:
  std::string se_file_path_;
  ALuint source_;
  ALuint buffer_;
};

namespace AlureSePlayer {
  bool Play(AlureSe &se, const glm::vec3 &pos = glm::vec3());
  bool Stop(AlureSe &se);
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_ALURE */

#endif /* MOJGAMELIB_AUDIO_SEPLAYER_H_ */

/**
 * Copyright (C) 2015 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUDIO_BGMPLAYER_H_
#define MOJGAMELIB_AUDIO_BGMPLAYER_H_

#include "mojgame/includer/al_include.h"

#ifdef MOJGAMELIB_WITH_ALURE

namespace mojgame {

class AlureBgm {
 public:
  AlureBgm(const char *bgm_file_path);
  ~AlureBgm() {
  }

  bool Initialize(float pitch, float gain);
  void Finalize();

  void ChangePitch(float pitch);
  void ChangeGain(float gain);

  const std::string &bgm_file_path() const {
    return bgm_file_path_;
  }
  ALuint source() const {
    return source_;
  }
  alureStream *stream() const {
    return stream_;
  }

 private:
  std::string bgm_file_path_;
  ALuint source_;
  alureStream *stream_;
};

namespace AlureBgmPlayer {
  bool Play(AlureBgm &bgm, int loopcount);
  bool Stop(AlureBgm &bgm);
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_ALURE */

#endif /* MOJGAMELIB_AUDIO_BGMPLAYER_H_ */

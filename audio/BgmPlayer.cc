/**
 * Copyright (C) 2015 The Motel on Jupiter
 */
#include "mojgame/audio/BgmPlayer.h"
#include "mojgame/includer/al_include.h"
#include "mojgame/logging/Logger.h"

#ifdef MOJGAMELIB_WITH_ALURE

namespace mojgame {

AlureBgm::AlureBgm(const char *bgm_file_path) :
  bgm_file_path_(bgm_file_path),
  source_(0),
  stream_(nullptr) {
}

bool AlureBgm::Initialize(float pitch, float gain) {
  if (source_ != 0 || stream_ != nullptr) {
    mojgame::LOGGER().Error("Not finalized");
    return false;
  }
  alGenSources(1, &source_);
  if (alGetError() != AL_NO_ERROR) {
    mojgame::LOGGER().Error("Failed to create OpenAL source");
    return false;
  }
  alSourcef(source_, AL_PITCH, pitch);
  alSourcef(source_, AL_GAIN, gain);

  // Invalidate 3D effect
  alSourcei(source_, AL_SOURCE_RELATIVE, AL_TRUE);
  alSourcef(source_, AL_ROLLOFF_FACTOR, 0.0f);

  alureStreamSizeIsMicroSec(AL_TRUE);
  stream_ = alureCreateStreamFromFile(bgm_file_path_.c_str(), 250000, 0, nullptr);
  if(stream_ == nullptr) {
    mojgame::LOGGER().Error("Failed to create stream with audio file "
                            "(file: %s, errmsg: %s)",
                            bgm_file_path_.c_str(), alureGetErrorString());
    alDeleteSources(1, &source_);
    return false;
  }
  return true;
}

void AlureBgm::ChangePitch(float pitch) {
  alSourcef(source_, AL_PITCH, pitch);
}

void AlureBgm::ChangeGain(float gain) {
  alSourcef(source_, AL_GAIN, gain);
}

void AlureBgm::Finalize() {
  if (stream_ != nullptr) {
    ALboolean ok = alureDestroyStream(stream_, 0, nullptr);
    stream_ = nullptr;
    if (!ok) {
      mojgame::LOGGER().Warn("Failed to destory stream (errmsg: %s)",
                             alureGetErrorString());
    }
  }
  if (source_ != 0) {
    alDeleteSources(1, &source_);
    source_ = 0;
  }
}

static void OnPlayingFinish(void *userdata, ALuint source) {
  UNUSED(userdata);
  UNUSED(source);
}

bool AlureBgmPlayer::Play(AlureBgm &bgm, int loopcount) {
  if(!alurePlaySourceStream(bgm.source(), bgm.stream(), 3, loopcount, OnPlayingFinish, nullptr)) {
    mojgame::LOGGER().Error("Failed to play bgm (errmsg: %s)",
                            alureGetErrorString());
    return false;
  }
  return true;
}

bool AlureBgmPlayer::Stop(AlureBgm &bgm) {
  if(!alureStopSource(bgm.source(), AL_FALSE)) {
    mojgame::LOGGER().Error("Failed to stop bgm (errmsg: %s)",
                            alureGetErrorString());
    return false;
  }
  return true;
}

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_ALURE */

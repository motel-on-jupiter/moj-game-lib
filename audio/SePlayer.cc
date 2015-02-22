/**
 * Copyright (C) 2015 The Motel on Jupiter
 */
#include "mojgame/audio/SePlayer.h"
#include "mojgame/includer/al_include.h"
#include "mojgame/logging/Logger.h"

#ifdef MOJGAMELIB_WITH_ALURE

namespace mojgame {

AlureSe::AlureSe(const char *se_file_path) :
  se_file_path_(se_file_path),
  source_(0),
  buffer_(0) {
}

bool AlureSe::Initialize(float pitch, float gain) {
  if (source_ != 0 || buffer_ != 0) {
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

  buffer_ = alureCreateBufferFromFile(se_file_path_.c_str());
  if(buffer_ == 0) {
    mojgame::LOGGER().Error("Failed to create buffer with audio file "
                            "(file: %s, errmsg: %s)",
                            se_file_path_.c_str(), alureGetErrorString());
    alDeleteSources(1, &source_);
    return false;
  }
  alSourcei(source_, AL_BUFFER, buffer_);
  return true;
}

void AlureSe::ChangePitch(float pitch) {
  alSourcef(source_, AL_PITCH, pitch);
}

void AlureSe::ChangeGain(float gain) {
  alSourcef(source_, AL_GAIN, gain);
}

void AlureSe::Finalize() {
  if (buffer_ != 0) {
    alDeleteBuffers(1, &buffer_);
    buffer_ = 0;
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

bool AlureSePlayer::Play(AlureSe &se) {
  if(!alurePlaySource(se.source(), OnPlayingFinish, nullptr)) {
    mojgame::LOGGER().Error("Failed to play se (errmsg: %s)",
                            alureGetErrorString());
    return false;
  }
  return true;
}

bool AlureSePlayer::Stop(AlureSe &se) {
  if(!alureStopSource(se.source(), AL_FALSE)) {
    mojgame::LOGGER().Error("Failed to stop se (errmsg: %s)",
                            alureGetErrorString());
    return false;
  }
  return true;
}

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_ALURE */

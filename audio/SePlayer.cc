/**
 * Copyright (C) 2015 The Motel on Jupiter
 */
#include "mojgame/audio/SePlayer.h"
#include "mojgame/includer/al_include.h"
#include "mojgame/logging/Logger.h"

#ifdef MOJGAMELIB_WITH_ALURE

namespace mojgame {

AlureSe::AlureSe(const char *se_file_path, unsigned int source_slot_length) :
  se_file_path_(se_file_path),
  slot_length_(source_slot_length),
  active_slot_(0),
  source_slot_(nullptr),
  buffer_(0) {
}

bool AlureSe::Initialize(float pitch, float gain) {
  if (source_slot_ != nullptr || buffer_ != 0) {
    mojgame::LOGGER().Error("Not finalized");
    return false;
  }
  source_slot_ = new unsigned int[slot_length_];
  if (source_slot_ == nullptr) {
    mojgame::LOGGER().Error("Failed to allocate source slot");
    return false;
  }
  alGenSources(slot_length_, source_slot_);
  if (alGetError() != AL_NO_ERROR) {
    mojgame::LOGGER().Error("Failed to create OpenAL source");
    return false;
  }

  buffer_ = alureCreateBufferFromFile(se_file_path_.c_str());
  if(buffer_ == 0) {
    mojgame::LOGGER().Error("Failed to create buffer with audio file "
                            "(file: %s, errmsg: %s)",
                            se_file_path_.c_str(), alureGetErrorString());
    Finalize();
    return false;
  }
  for (unsigned int i=0; i<slot_length_; ++i) {
    alSourcef(source_slot_[i], AL_PITCH, pitch);
    alSourcef(source_slot_[i], AL_GAIN, gain);
    alSourcei(source_slot_[i], AL_BUFFER, buffer_);
  }
  return true;
}

void AlureSe::Finalize() {
  if (buffer_ != 0) {
    alDeleteBuffers(1, &buffer_);
    buffer_ = 0;
  }
  if (source_slot_ != nullptr) {
    alDeleteSources(slot_length_, source_slot_);
    free(source_slot_);
    source_slot_ = nullptr;
  }
}

static void OnPlayingFinish(void *userdata, ALuint source) {
  UNUSED(userdata);
  UNUSED(source);
}

int AlureSePlayer::Play(AlureSe &se, const glm::vec3 &pos, float pitch,
                        float gain) {
  int slot_idx = se.RotateSlot();
  ALuint source = se.GetSource(slot_idx);
  if (source == 0) {
    mojgame::LOGGER().Error("Failed to get valid source");
    return 0;
  }
  if (pitch >= 0.0f) {
    alSourcef(source, AL_PITCH, pitch);
  }
  if (gain >= 0.0f) {
    alSourcef(source, AL_GAIN, gain);
  }
  alSource3f(source, AL_POSITION, pos.x, pos.y, pos.z);
  if(!alurePlaySource(source, OnPlayingFinish, nullptr)) {
    mojgame::LOGGER().Error("Failed to play se (errmsg: %s)",
                            alureGetErrorString());
    return 0;
  }
  return slot_idx;
}

bool AlureSePlayer::Stop(AlureSe &se, int slot_idx) {
  ALuint source = se.GetSource(slot_idx);
  if (source == 0) {
    mojgame::LOGGER().Error("Failed to get valid source");
    return false;
  }
  if(!alureStopSource(source, AL_FALSE)) {
    mojgame::LOGGER().Error("Failed to stop se (errmsg: %s)",
                            alureGetErrorString());
    return false;
  }
  return true;
}

} /* namespace mojgame */

#endif /* MOJGAMELIB_WITH_ALURE */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/logging/emitter/FileLogEmitter.h"

namespace mojgame {

StdoutLogEmitter &STDOUT_LOG_EMITTER() {
  return StdoutLogEmitter::GetMutableInstance();
}
StderrLogEmitter &STDERR_LOG_EMITTER() {
  return StderrLogEmitter::GetMutableInstance();
}

} /* namespace mojgame */

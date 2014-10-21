/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/logging/LogEmitter.h"
#include <cstdarg>

namespace mojgame {

LogEmitter::LogEmitter() {
}

LogEmitter::~LogEmitter() {
}

void LogEmitter::Emit(const char* prefix, const char* format, ...) {
  va_list args;
  va_start(format, args);
  Emitv(prefix, format, args);
  va_end(args);
}

} /* namespace mojgame */

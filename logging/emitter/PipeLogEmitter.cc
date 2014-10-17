/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/logging/emitter/PipeLogEmitter.h"
#include <cstdio>

namespace mojgame {

PipeLogEmitter::PipeLogEmitter(FILE *pipe)
    : LogEmitter(),
      pipe_(pipe) {
}

PipeLogEmitter::~PipeLogEmitter() {
}

int PipeLogEmitter::Initialize() {
  if (OpenPipe() < 0) {
    return -1;
  }
  return 0;
}

int PipeLogEmitter::Finalize() {
  if (ClosePipe() < 0) {
    return -1;
  }
  return 0;
}

void PipeLogEmitter::Emitv(const char *prefix, const char *format,
                           va_list args) {
  fprintf(pipe_, prefix);
  vfprintf(pipe_, format, args);
  fprintf(pipe_, "\n");
}

} /* namespace mojgame */

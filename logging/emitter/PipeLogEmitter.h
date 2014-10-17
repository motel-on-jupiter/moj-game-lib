/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_LOGGING_EMITTER_PIPELOGEMITTER_H_
#define MOJGAMELIB_LOGGING_EMITTER_PIPELOGEMITTER_H_

#include <cstdio>
#include "mojgame/logging/emitter/LogEmitter.h"

namespace mojgame {

class PipeLogEmitter : public LogEmitter {
 public:
  PipeLogEmitter(FILE *pipe);
  virtual ~PipeLogEmitter();

  virtual int Initialize();
  virtual int Finalize();

  virtual void Emitv(const char *prefix, const char *format, va_list args);

 protected:
  virtual int OpenPipe() = 0;
  virtual int ClosePipe() = 0;

 private:
  FILE *pipe_;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_LOGGING_EMITTER_PIPELOGEMITTER_H_ */

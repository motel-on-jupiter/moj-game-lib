/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_LOGEMITTER_PIPELOGEMITTER_H_
#define MOJGAMELIB_CATALOGUE_LOGEMITTER_PIPELOGEMITTER_H_

#include <cstdio>
#include "mojgame/logging/LogEmitter.h"

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

#endif /* MOJGAMELIB_CATALOGUE_LOGEMITTER_PIPELOGEMITTER_H_ */

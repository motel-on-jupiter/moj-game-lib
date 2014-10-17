/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_LOGGING_EMITTER_LOGEMITTER_H_
#define MOJGAMELIB_LOGGING_EMITTER_LOGEMITTER_H_

#include <cstdarg>

namespace mojgame {

class LogEmitter {
 public:
  LogEmitter();
  virtual ~LogEmitter();

  virtual void Emit(const char *prefix, const char *format, ...);
  virtual void Emitv(const char *prefix, const char *format, va_list args) = 0;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_LOGGING_EMITTER_LOGEMITTER_H_ */

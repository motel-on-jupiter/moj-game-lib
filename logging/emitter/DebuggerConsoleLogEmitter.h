/**
 * Copyright (C) 2014 The Motel on Jupiter
 */

#ifndef MOJGAME_LOGGING_EMITTER_DEBUGGERCONSOLELOGEMITTER_H_
#define MOJGAME_LOGGING_EMITTER_DEBUGGERCONSOLELOGEMITTER_H_

#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/logging/emitter/LogEmitter.h"

namespace mojgame {

class DebuggerConsoleLogEmitter : public LogEmitter, public Singleton<
    DebuggerConsoleLogEmitter> {
 public:
  enum {
    kMaxEmittableSize = 1024
  };

  DebuggerConsoleLogEmitter();
  virtual ~DebuggerConsoleLogEmitter();

  virtual int Initialize();
  virtual int Finalize();

  virtual void Emitv(const char *prefix, const char *format, va_list args);

 private:
  virtual int EmitMultibyteChars(const char *mbchars);
  virtual int EmitPrefix(const char *prefix);
  virtual int EmitBody(const char *format, va_list args);
};

extern DebuggerConsoleLogEmitter &DEBUGGER_CONSOLE_LOG_EMITTER();

} /* namespace mojgame */

#endif /* MOJGAME_LOGGING_EMITTER_DEBUGGERCONSOLELOGEMITTER_H_ */

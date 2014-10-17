/**
 * Copyright (C) 2014 The Motel on Jupiter
 */

#ifndef MOJGAMELIB_LOGGING_EMITTER_MESSAGEBOXLOGEMITTER_H_
#define MOJGAMELIB_LOGGING_EMITTER_MESSAGEBOXLOGEMITTER_H_

#include <tchar.h>
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/logging/emitter/LogEmitter.h"

namespace mojgame {

class MessageBoxLogEmitter : public LogEmitter, public Singleton<
    MessageBoxLogEmitter> {
 public:
  enum {
    kMaxEmittableSize = 1024
  };
  static const TCHAR *kMessageBoxCaption;

  MessageBoxLogEmitter();
  virtual ~MessageBoxLogEmitter();

  virtual int Initialize();
  virtual int Finalize();

  virtual void Emitv(const char *prefix, const char *format, va_list args);
};

extern MessageBoxLogEmitter &MESSAGE_BOX_LOG_EMITTER();

} /* namespace mojgame */

#endif /* MOJGAMELIB_LOGGING_EMITTER_MESSAGEBOXLOGEMITTER_H_*/

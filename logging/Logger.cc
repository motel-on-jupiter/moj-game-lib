/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/logging/Logger.h"

namespace mojgame {

const char *Logger::kLogPrefixes[] = {
    "",         //kNoneLevel
    "[TRACE]",  //kTrace
    "[DEBUG]",  //kDebug
    "[INFO]",   //kInfo
    "[NOTICE]",  //kNotice
    "[WARN]",   //kWarn
    "[ERROR]",  //kError
    "[CRIT]",   //kCrit,
    };

Logger::Logger()
    : Singleton<Logger>(),
      emitters_() {
}

Logger::~Logger() {
}

Logger &LOGGER() {
  return Logger::GetMutableInstance();
}

} /* namespace mojgame */

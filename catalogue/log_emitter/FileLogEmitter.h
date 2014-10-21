/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_CATALOGUE_LOGEMITTER_FILELOGEMITTER_H_
#define MOJGAMELIB_CATALOGUE_LOGEMITTER_FILELOGEMITTER_H_

#include <cstdio>
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/catalogue/log_emitter/PipeLogEmitter.h"

namespace mojgame {

class StdoutLogEmitter : public PipeLogEmitter, public Singleton<
    StdoutLogEmitter> {
 public:
  StdoutLogEmitter()
      : PipeLogEmitter(stdout) {
  }
  virtual ~StdoutLogEmitter() {
  }

 protected:
  virtual int OpenPipe() {
    return 0;
  }
  virtual int ClosePipe() {
    return 0;
  }
};

class StderrLogEmitter : public PipeLogEmitter, public Singleton<
    StderrLogEmitter> {
 public:
  StderrLogEmitter()
      : PipeLogEmitter(stderr) {
  }
  virtual ~StderrLogEmitter() {
  }

 protected:
  virtual int OpenPipe() {
    return 0;
  }
  virtual int ClosePipe() {
    return 0;
  }
};

template<const char *filepath>
class FileLogEmitter : public PipeLogEmitter, public Singleton<
    FileLogEmitter<filepath>> {
 public:
  FileLogEmitter()
      : PipeLogEmitter(nullptr) {
  }
  virtual ~FileLogEmitter() {
  }

 protected:
  virtual int OpenPipe() {
    pipe_ = fopen(filepath, "a");
    if (nullptr == pipe_) {
      return -1;
    }
    return 0;
  }
  virtual int ClosePipe() {
    if (nullptr != pipe_) {
      if (EOF == fclose(pipe_)) {
        return -1;
      }
    }
    return 0;
  }
};

extern StdoutLogEmitter &STDOUT_LOG_EMITTER();
extern StderrLogEmitter &STDERR_LOG_EMITTER();
template<const char *filepath> FileLogEmitter<filepath> &FILE_LOG_EMITTER() {
  return FileLogEmitter<filepath>::GetMutableInstance();
}

} /* namespace mojgame */

#endif /* MOJGAMELIB_CATALOGUE_LOGEMITTER_FILELOGEMITTER_H_ */

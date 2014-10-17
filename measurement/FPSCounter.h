/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_MEASUREMENT_FPSCOUNTER_H_
#define MOJGAMELIB_MEASUREMENT_FPSCOUNTER_H_

namespace mojgame {

class FPSCounter {
 public:
  FPSCounter(int sampling_msec);
  ~FPSCounter() {
  }

  void Update(int current_msec);

  int sampling_msec() const {
    return sampling_msec_;
  }
  int fps() const {
    return fps_;
  }

 private:
  int sampling_msec_;
  int fps_;
  int count_;
  int count_start_msec;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_MEASUREMENT_FPSCOUNTER_H_ */

/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_CSYNTAXAUX_H_
#define MOJGAMELIB_AUXILIARY_CSYNTAXAUX_H_

#define UNUSED(_arg) do { (void)(_arg); } while(0)
#define SAFE_STR(_str) ((_str == nullptr) ? "(null)" : _str)

#ifdef _MSC_VER
#include <Windows.h>
#else
#ifndef ARRAYSIZE
#define ARRAYSIZE(_var) (sizeof(_var) / sizeof((_var)[0]))
#endif
#endif

#include <memory>

namespace mojgame {

template<class T>
class NonCopyable {
 protected:
  NonCopyable() {
  }
  ~NonCopyable() {
  }

 private:
  NonCopyable(const NonCopyable&);
  NonCopyable& operator=(const NonCopyable &);
  T& operator=(const T &);
};

template<class T>
class Singleton {
 public:
  static const T &GetInstance() {
    return GetMutableInstance();
  }
  static T &GetMutableInstance() {
    static T s_singleton;
    return s_singleton;
  }

 protected:
  Singleton() {
  }

 private:
  Singleton(const Singleton &) = delete;
  Singleton& operator=(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton& operator=(Singleton &&) = delete;
};

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_CSYNTAXAUX_H_ */

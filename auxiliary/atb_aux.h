/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_ATBAUX_H_
#define MOJGAMELIB_AUXILIARY_ATBAUX_H_

#include <map>
#include <sstream>
#include <string>
#include "mojgame/includer/atb_include.h"
#include "mojgame/logging/Logger.h"

namespace mojgame {

namespace atb_aux {

extern void DefineMenu(const glm::i32vec2 pos, int width, int height,
                       const unsigned char (&color)[3], const char *option_def =
                           nullptr);

extern void AddInt8VarRO(TwBar &bar, const char *group, const char *label,
                         const int8_t &var, const char *option_def = nullptr);
extern void AddInt32VarRO(TwBar &bar, const char *group, const char *label,
                          const int32_t &var, const char *option_def = nullptr);

extern void AddVarRW(TwBar &bar, const char *group, const char *label,
                     TwType type, void *var, const char *option_def = nullptr);
extern void AddBoolVarRW(TwBar &bar, const char *group, const char *label,
                         bool &var, const char *option_def = nullptr);
extern void AddCharVarRW(TwBar &bar, const char *group, const char *label,
                         char &var, const char *option_def = nullptr);
extern void AddUint32VarRW(TwBar &bar, const char *group, const char *label,
                           uint32_t &var, const char *option_def = nullptr);
extern void AddInt32VarRW(TwBar &bar, const char *group, const char *label,
                          int32_t &var, const char *option_def = nullptr);
extern void AddFloatVarRW(TwBar &bar, const char *group, const char *label,
                          float &var, const char *option_def = nullptr);
extern void AddDoubleVarRW(TwBar &bar, const char *group, const char *label,
                           double &var, const char *option_def = nullptr);
extern void AddColor32VarRW(TwBar &bar, const char *group, const char *label,
                            char (&var)[4], const char *option_def = nullptr);
extern void AddColor3fVarRW(TwBar &bar, const char *group, const char *label,
                            glm::vec3 &var, const char *option_def = nullptr);
extern void AddColor4fVarRW(TwBar &bar, const char *group, const char *label,
                            glm::vec4 &var, const char *option_def = nullptr);
extern void AddQuat4fVarRW(TwBar &bar, const char *group, const char *label,
                           glm::quat &var, const char *option_def = nullptr);
extern void AddQuat4dVarRW(TwBar &bar, const char *group, const char *label,
                           glm::dquat &var, const char *option_def = nullptr);
extern void AddDir3fVarRW(TwBar &bar, const char *group, const char *label,
                          glm::vec3 &var, const char *option_def = nullptr);
extern void AddDir3dVarRW(TwBar &bar, const char *group, const char *label,
                          glm::f64vec3 &var, const char *option_def = nullptr);
template<typename EnumType> void AddEnumVarRW(
    TwBar &bar, const char *group, const char *label,
    const std::map<int, std::string> &enum_map, EnumType &var,
    const char *option_def = nullptr) {
  std::stringstream enum_name;
  enum_name << group << "_" << label << "_Enum";
  std::vector<TwEnumVal> enum_values;
  for (auto it = enum_map.begin(); it != enum_map.end(); ++it) {
    TwEnumVal enum_value = { (*it).first, (*it).second.c_str() };
    enum_values.push_back(enum_value);
  }
  TwType type = TwDefineEnum(enum_name.str().c_str(), enum_values.data(),
                             enum_values.size());
  if (type == TW_TYPE_UNDEF) {
    mojgame::LOGGER().Warn("Failed to define enum (errmsg: %s)",
                           TwGetLastError());
    return;
  }
  return AddVarRW(bar, group, label, type, &var, option_def);
}

extern void AddButton(TwBar &bar, const char *group, const char *label,
                      TwButtonCallback callback, void *client_data,
                      const char *option_def = nullptr);

extern void RemoveVar(TwBar &bar, const char *group, const char *label);

extern int TwEventSDL20(const void *sdlEvent);

} /* namespace atb_aux */

} /* namespace mojgame */

#endif /* MOJGAMELIB_AUXILIARY_ATBAUX_H_ */

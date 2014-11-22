/**
 * Copyright (C) 2014 The Motel on Jupiter
 */
#include "mojgame/auxiliary/atb_aux.h"
#include <sstream>
#include <string>
extern "C" {
#include "mojgame/external/TwEventSDL20.c"
}
#include "mojgame/logging/Logger.h"

namespace mojgame {

namespace atb_aux {

inline void DefineMenu(const glm::i32vec2 pos, int width, int height,
                       const unsigned char (&color)[3],
                       const char *option_def) {
  std::stringstream tw_def;
  tw_def << "TweakMenu position='" << pos.x << " " << pos.y << "' size='"
         << width << " " << height << "' color='" << static_cast<int>(color[0])
         << " " << static_cast<int>(color[1]) << " "
         << static_cast<int>(color[2]) << "'";
  if (option_def != nullptr) {
    tw_def << " " << option_def;
  }
  if (TwDefine(tw_def.str().c_str()) == 0) {
    mojgame::LOGGER().Warn("Failed to define menu (errmsg: %s, text: %s)",
                           TwGetLastError(), tw_def.str().c_str());
  }
}

inline static void AddVarRO(TwBar &bar, const char *group, const char *label,
                            TwType type, const void *var,
                            const char *option_def) {
  std::stringstream name;
  name << group << "_" << label;
  std::stringstream def;
  def << "group='" << group << "' label='" << label << "'";
  if (option_def != nullptr) {
    def << " " << option_def;
  }
  if (TwAddVarRO(&bar, name.str().c_str(), type, var, def.str().c_str()) == 0) {
    mojgame::LOGGER().Warn(
        "Failed to add read-only variable (group: %s, label: %s, errmsg: %s)",
        group, label, TwGetLastError());
  }
}
inline void AddInt8VarRO(TwBar &bar, const char *group, const char *label,
                         const int8_t &var, const char *option_def) {
  return AddVarRO(bar, group, label, TW_TYPE_INT8, &var, option_def);
}
inline void AddInt32VarRO(TwBar &bar, const char *group, const char *label,
                          const int32_t &var, const char *option_def) {
  return AddVarRO(bar, group, label, TW_TYPE_INT32, &var, option_def);
}

inline void AddVarRW(TwBar &bar, const char *group, const char *label,
                     TwType type, void *var, const char *option_def) {
  std::stringstream name;
  name << group << "_" << label;
  std::stringstream def;
  def << "group='" << group << "' label='" << label << "'";
  if (option_def != nullptr) {
    def << " " << option_def;
  }
  if (TwAddVarRW(&bar, name.str().c_str(), type, var, def.str().c_str()) == 0) {
    mojgame::LOGGER().Warn(
        "Failed to add read-write variable (group: %s, label: %s, errmsg: %s)",
        group, label, TwGetLastError());
  }
}
inline void AddBoolVarRW(TwBar &bar, const char *group, const char *label,
                         bool &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_BOOLCPP, &var, option_def);
}
inline void AddCharVarRW(TwBar &bar, const char *group, const char *label,
                         char &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_CHAR, &var, option_def);
}
inline void AddInt32VarRW(TwBar &bar, const char *group, const char *label,
                          int32_t &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_INT32, &var, option_def);
}
inline void AddUint32VarRW(TwBar &bar, const char *group, const char *label,
                           uint32_t &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_UINT32, &var, option_def);
}
inline void AddFloatVarRW(TwBar &bar, const char *group, const char *label,
                          float &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_FLOAT, &var, option_def);
}
inline void AddDoubleVarRW(TwBar &bar, const char *group, const char *label,
                           float &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_DOUBLE, &var, option_def);
}
inline void AddColor32VarRW(TwBar &bar, const char *group, const char *label,
                            char (&var)[4], const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_COLOR32, &var, option_def);
}
inline void AddColor3fVarRW(TwBar &bar, const char *group, const char *label,
                            glm::vec3 &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_COLOR3F, &var, option_def);
}
inline void AddColor4fVarRW(TwBar &bar, const char *group, const char *label,
                            glm::vec4 &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_COLOR4F, &var, option_def);
}
inline void AddQuat4fVarRW(TwBar &bar, const char *group, const char *label,
                           glm::quat &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_QUAT4F, &var, option_def);
}
inline void AddQuat4dVarRW(TwBar &bar, const char *group, const char *label,
                           glm::dquat &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_QUAT4D, &var, option_def);
}
inline void AddDir3fVarRW(TwBar &bar, const char *group, const char *label,
                          glm::vec3 &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_DIR3F, &var, option_def);
}
inline void AddDir3dVarRW(TwBar &bar, const char *group, const char *label,
                          glm::f64vec3 &var, const char *option_def) {
  return AddVarRW(bar, group, label, TW_TYPE_DIR3D, &var, option_def);
}

inline void AddButton(TwBar &bar, const char *group, const char *label,
                      TwButtonCallback callback, void *client_data,
                      const char *option_def) {
  std::stringstream name;
  name << group << "_" << label;
  std::stringstream def;
  def << "group='" << group << "' label='" << label << "'";
  if (option_def != nullptr) {
    def << " " << option_def;
  }
  if (TwAddButton
      (&bar, name.str().c_str(), callback, client_data, def.str().c_str()) == 0) {
    mojgame::LOGGER().Warn(
        "Failed to add button (group: %s, label: %s, errmsg: %s)",
        group, label, TwGetLastError());
  }
}

inline void RemoveVar(TwBar &bar, const char *group, const char *label) {
  std::stringstream name;
  name << group << "_" << label;
  if (TwRemoveVar(&bar, name.str().c_str()) == 0) {
    mojgame::LOGGER().Warn(
        "Failed to remove variable (group: %s, label: %s, errmsg: %s)", group,
        label, TwGetLastError());
  }
}

inline int TwEventSDL20(const void *sdlEvent) {
  return ::TwEventSDL20(sdlEvent);
}

} /* namespace atb_aux */

} /* namespace mojgame */

/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAME_CATALOGUE_RENDERER_RIPPLERENDERER_H_
#define MOJGAME_CATALOGUE_RENDERER_RIPPLERENDERER_H_

#include <utility>
#include <vector>
#include "mojgame/catalogue/renderer/GradationalRenderer.h"
#include "mojgame/misc/RadiconMover.h"

namespace mojgame {

struct RippleStimulus {
  glm::vec2 pos;
  glm::vec3 color;
  float effect;

  RippleStimulus()
      : pos(),
        color(),
        effect(0.0f) {
  }
  RippleStimulus(glm::vec2 pos, glm::vec3 color, float effect)
      : pos(pos),
        color(color),
        effect(effect) {
  }
  void Clear() {
    pos = glm::vec2();
    color = glm::vec3();
    effect = 0.0f;
  }
};

class RippleStimulatorInterface {
 public:
  RippleStimulatorInterface() {
  }
  virtual ~RippleStimulatorInterface() {
  }
  virtual void Generate(const glm::vec2 &window_size,
                        RippleStimulus &stimulus) = 0;
  virtual bool IsDead() const = 0;
};

class OneshotRippleStimulator : public RippleStimulatorInterface {
 public:
  OneshotRippleStimulator(const RippleStimulus &stimulus)
      : stimulus_(stimulus) {
  }
  void Generate(const glm::vec2 &window_size, RippleStimulus &stimulus) {
    UNUSED(window_size);

    stimulus = stimulus_;
    stimulus_.Clear();
  }
  bool IsDead() const {
    return true;
  }

 private:
  RippleStimulus stimulus_;
};

class RandomRippleStimulator : public RippleStimulatorInterface {
 public:
  RandomRippleStimulator(const glm::vec3 &color,
                         const glm::vec2 &effect_range)
      : color_(color),
        effect_range_(effect_range) {
  }
  void Generate(const glm::vec2 &window_size, RippleStimulus &stimulus);
  virtual bool IsDead() const {
    return true;
  }

  void set_effect_range(const glm::vec2 &effect_range) {
    effect_range_ = effect_range;
  }

 private:
  glm::vec3 color_;
  glm::vec2 effect_range_;
  RippleStimulus stimulus_;
};

class RainyRippleStimulator : public RandomRippleStimulator {
 public:
  RainyRippleStimulator(const glm::vec3 &color,
                        const glm::vec2 &effect_range)
      : RandomRippleStimulator(color, effect_range) {
  }
  bool IsDead() const {
    return false;
  }
};

class RippleGLRenderer : public GradationalGLRenderer {
 public:
  RippleGLRenderer();
  ~RippleGLRenderer();

  bool Receive(const RippleStimulus &stimulus);
  void Attach(RippleStimulatorInterface &stimulator);
  void DettachAll();

 protected:
  bool OnRendering(const glm::vec2 &window_size);

 private:
  typedef std::pair<RippleStimulatorInterface *, bool> AttachedStimulator;
  std::vector<AttachedStimulator> stimulators_;
};

} /* namespace mojgame */

#endif /* MOJGAME_CATALOGUE_RENDERER_RIPPLERENDERER_H_ */

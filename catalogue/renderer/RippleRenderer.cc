/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/catalogue/renderer/RippleRenderer.h"
#include "mojgame/auxiliary/gl/gl_shader.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/catalogue/renderer/GradationalRenderer.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"
#include "mojgame/misc/RadiconMover.h"

#define SHADER_SOURCE(version, ...) "#version " #version "\n" #__VA_ARGS__

static const char kVShaderSource[] = SHADER_SOURCE(330 core,
layout(location = 0) in vec2 coord;
layout(location = 1) in vec2 uv;

out vec2 vertexUv;

void main(void) {
  gl_Position.xy = coord;
  gl_Position.z = 0.0;
  gl_Position.w = 1.0;
  vertexUv = uv;
}
);

static const char kFShaderSource[] = SHADER_SOURCE(330 core,
in vec2 vertexUv;

layout (location = 0) out vec4 fragmentColor;

uniform sampler2D prev0_tex;
uniform sampler2D prev1_tex;
uniform vec2 windowSize;
uniform vec2 stimulusPoss[10];
uniform float stimulusEffects[10];

const float kEpsilon = 0.0000001;

void main(void) {
  vec2 texelSize = vec2(1.0) / windowSize;
  for (int i = 0; i < 10; ++i) {
    if (length(stimulusPoss[i]) > kEpsilon) {
      if ((abs(stimulusPoss[i].x - vertexUv.x) < texelSize.x * 0.6) &&
          (abs(stimulusPoss[i].y - vertexUv.y) < texelSize.y * 0.6)) {
        fragmentColor = vec4(stimulusEffects[i]);
        return;
      }
    }
  }

  fragmentColor = texture2D(prev0_tex, vertexUv);
  if (vertexUv.x - texelSize.x > 0.0 && vertexUv.y - texelSize.y > 0.0) {
    fragmentColor += texture2D(prev0_tex, vertexUv + texelSize * vec2(-1.0, -1.0));
  } else {
    fragmentColor += texture2D(prev0_tex, vertexUv);
  }
  if (vertexUv.x - texelSize.x > 0.0 && vertexUv.y + texelSize.y < 1.0) {
    fragmentColor += texture2D(prev0_tex, vertexUv + texelSize * vec2(-1.0, 1.0));
  } else {
    fragmentColor += texture2D(prev0_tex, vertexUv);
  }
  if (vertexUv.x + texelSize.x < 1.0 && vertexUv.y - texelSize.y > 0.0) {
    fragmentColor += texture2D(prev0_tex, vertexUv + texelSize * vec2(1.0, -1.0));
  } else {
    fragmentColor += texture2D(prev0_tex, vertexUv);
  }
  if (vertexUv.x + texelSize.x < 1.0 && vertexUv.y + texelSize.y < 1.0) {
    fragmentColor += texture2D(prev0_tex, vertexUv + texelSize * vec2(1.0, 1.0));
  } else {
    fragmentColor += texture2D(prev0_tex, vertexUv);
  }
  fragmentColor *= 0.25;
  fragmentColor *= 0.79;
  fragmentColor += texture2D(prev0_tex, vertexUv) - texture2D(prev1_tex, vertexUv);
  fragmentColor.a = 1.0;
}
);

namespace mojgame {

void RandomRippleStimulator::Generate(const glm::vec2 &window_size,
                                      RippleStimulus &stimulus) {
  UNUSED(window_size);

  stimulus.pos = glm::linearRand(glm::vec2(0.0f), glm::vec2(1.0f));
  stimulus.effect = glm::linearRand(0.0f, 1.0f);
}

RippleGLRenderer::RippleGLRenderer()
    : mojgame::GradationalGLRenderer(kVShaderSource, kFShaderSource, 3),
      stimulators_() {
}

RippleGLRenderer::~RippleGLRenderer() {
  for (auto it = stimulators_.begin(); it != stimulators_.end(); ++it) {
    if (it->second) {
      delete it->first;
    }
  }
}

bool RippleGLRenderer::Receive(const RippleStimulus &stimulus) {
  RippleStimulatorInterface *stimulator = new OneshotRippleStimulator(stimulus);
  if (stimulator == nullptr) {
    LOGGER().Error("Failed to create stimulator");
    return false;
  }
  stimulators_.push_back(AttachedStimulator(stimulator, true));
  return true;
}

void RippleGLRenderer::Attach(RippleStimulatorInterface &stimulator) {
  stimulators_.push_back(AttachedStimulator(&stimulator, false));
}

bool RippleGLRenderer::OnRendering(const glm::vec2 &window_size) {
  mojgame::gl_shader::set_uniform_2f(gradation_program(), "windowSize",
                                     window_size);
  RippleStimulus stimulus;
  std::vector<glm::vec2> stimulus_poss;
  std::vector<float> stimulus_effects;
  for (auto it = stimulators_.begin(); it != stimulators_.end();) {
    if (it->first != nullptr) {
      it->first->Generate(window_size, stimulus);
      stimulus_poss.push_back(stimulus.pos);
      stimulus_effects.push_back(stimulus.effect);
      if (it->first->IsDead()) {
        if (it->second) {
          delete it->first;
        }
        it = stimulators_.erase(it);
      } else {
        ++it;
      }
    }
  }
  stimulus_poss.resize(10);
  stimulus_effects.resize(10);
  mojgame::gl_shader::set_uniform_2fv(gradation_program(), "stimulusPoss",
                                      glm::value_ptr(stimulus_poss[0]), 10);
  mojgame::gl_shader::set_uniform_1fv(gradation_program(), "stimulusEffects",
                                      stimulus_effects.data(), 10);
  return mojgame::GradationalGLRenderer::OnRendering(window_size);
}

} /* namespace mojgame */

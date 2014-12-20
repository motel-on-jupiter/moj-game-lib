/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/catalogue/renderer/RippleRenderer.h"
#include "mojgame/auxiliary/gl/gl_shader.h"
#include "mojgame/auxiliary/csyntax_aux.h"
#include "mojgame/catalogue/renderer/GradationalRenderer.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

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
uniform vec2 dropPos;

const float kEpsilon = 0.0000001;

void main(void) {
  vec2 texelSize = vec2(1.0) / windowSize;
  if (length(dropPos) > kEpsilon) {
    if ((abs(dropPos.x - vertexUv.x) < texelSize.x * 0.6) &&
        (abs(dropPos.y - vertexUv.y) < texelSize.y * 0.6)) {
      fragmentColor = vec4(1.0);
      return;
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

RippleGLRenderer::RippleGLRenderer()
    : mojgame::GradationalGLRenderer(kVShaderSource, kFShaderSource, 3),
      stimulus_() {
}

bool RippleGLRenderer::OnRendering(const glm::vec2 &window_size) {
  mojgame::gl_shader::set_uniform_2f(gradation_program(), "windowSize", window_size);
  if (stimulus_.force > 0.0f) {
    mojgame::gl_shader::set_uniform_2f(gradation_program(), "dropPos", stimulus_.pos);
    stimulus_.Clear();
  } else {
    mojgame::gl_shader::set_uniform_2f(gradation_program(), "dropPos", glm::vec2(0.0f));
  }
  return mojgame::GradationalGLRenderer::OnRendering(window_size);
}

} /* namespace mojgame */

/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#include "mojgame/animation/AnimationDrawer.h"
#include "mojgame/animation/Animation.h"
#include "mojgame/animation/AnimationResource.h"
#include "mojgame/includer/gl_include.h"
#include "mojgame/includer/glm_include.h"

namespace mojgame {

AnimationDrawer::AnimationDrawer(
    const AnimationResource &resource)
    : resource_(resource) {
}

void AnimationDrawer::Draw(const Animation *anim,
                                       float time, const glm::vec2 &translation,
                                       float rotation,
                                       const glm::vec2 &scaling) {
  if (anim != nullptr) {
    const Animation::AnimationFrame *anim_frame = anim->GetFrame(
        time);
    if (anim_frame == nullptr) {
      return;
    }
    if (anim_frame->resource_id < 0) {
      mojgame::LOGGER().Error("Failed to get valid resource id (time: %f)",
                              time);
      return;
    }
    GLuint texname = resource_.texname(anim_frame->resource_id);
    if (texname == 0) {
      mojgame::LOGGER().Error(
          "Failed to get valid texture name (time: %f, resource_id: %d)", time,
          anim_frame->resource_id);
      return;
    }
    glBindTexture(GL_TEXTURE_2D, texname);
    glPushMatrix();
    glMultMatrixf(
        glm::value_ptr(
            glm::translate(glm::vec3(translation, 0.0f))
                * glm::toMat4(glm_aux::angleAxisZ(rotation))
                * glm::scale(glm::vec3(scaling, 0.0f))));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2fv(glm::value_ptr(glm::vec2(-0.5f)));
    glTexCoord2f(0.0f, 1.0f);
    glVertex2fv(glm::value_ptr(glm::vec2(-0.5f, 0.5f)));
    glTexCoord2f(1.0f, 1.0f);
    glVertex2fv(glm::value_ptr(glm::vec2(0.5f)));
    glTexCoord2f(1.0f, 0.0f);
    glVertex2fv(glm::value_ptr(glm::vec2(0.5f, -0.5f)));
    glEnd();
    glPopMatrix();
  }
}

} /* namespace mojgame */

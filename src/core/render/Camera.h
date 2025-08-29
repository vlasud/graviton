#pragma once
#include "glad/gl.h"
#include "glm/glm.hpp"

namespace Graviton
{

class Camera final
{
public:
  Camera() = default;

private:
  glm::mat4 m_view;
};

}

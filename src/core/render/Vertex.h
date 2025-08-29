#pragma once
#include "glm/vec3.hpp"

namespace Graviton
{

struct Vertex
{
  glm::vec3 position = {};
  glm::vec3 normal = {};
  glm::vec2 texcoord = {};
};

}
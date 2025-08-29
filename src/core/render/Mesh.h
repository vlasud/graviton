#pragma once
#include "glad/gl.h"
#include "glm/glm.hpp"

namespace Graviton
{

class Mesh final
{
public:
  explicit Mesh(std::string pathToObjFile);

private:
  GLuint m_vbo = 0u;
  GLuint m_vao = 0u;

  glm::mat4 m_view;
};

}

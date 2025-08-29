#pragma once
#include "glad/gl.h"
#include "glm/glm.hpp"
#include "Vertex.h"
#include <string>

namespace Graviton
{

class Mesh final
{
public:
  explicit Mesh(const std::string& pathToObjFile);

  void loadObj(const std::string& pathToObjFile);

private:
  GLuint m_vbo = 0u;
  GLuint m_ebo = 0u;
  GLuint m_vao = 0u;

  std::vector<Vertex> m_vertices;
  std::vector<uint32_t> m_indices;
};

}

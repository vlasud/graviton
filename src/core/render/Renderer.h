#pragma once
#include "glad/gl.h"
#include "glm/glm.hpp"

#include <cstdint>

namespace Graviton
{

class Renderer final
{
public:
  explicit Renderer(uint32_t width, uint32_t height);

  void draw();

private:
  void resize(uint32_t width, uint32_t height);
  GLuint compileShader(GLenum type, const char* source);
  void createPipeline();

  uint32_t m_width = 640u;
  uint32_t m_height = 480u;

  GLuint m_program = 0u;

  GLuint m_vao = 0u;
  GLuint m_vbo = 0u;
  GLuint m_ebo = 0u;
};

}

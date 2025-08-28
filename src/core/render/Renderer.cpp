#include "Renderer.h"

#include "glad/gl.h"
#include "glm/gtc/type_ptr.hpp"

#include <iostream>

namespace Graviton
{

namespace
{

const char* VS = R"GLSL(
#version 410 core
layout (location = 0) in vec3 aPos;
uniform mat4 u_MVP;
void main()
{
    gl_Position = u_MVP * vec4(aPos, 1.0);
}
)GLSL";

const char* FS = R"GLSL(
#version 410 core
out vec4 FragColor;
void main()
{
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
)GLSL";

}

Renderer::Renderer(const uint32_t width, const uint32_t height)
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glDepthMask(GL_TRUE);

  glDisable(GL_BLEND);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  resize(width, height);

  createPipeline();
}

void Renderer::draw()
{
  glClearColor(0.1f, 0.12f, 0.15f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUseProgram(m_program);

  const GLint location = glGetUniformLocation(m_program, "u_MVP");
  if (location >= 0)
  {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(m_mvp));
  }

  glBindVertexArray(m_vao);
  glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
}

void Renderer::resize(const uint32_t width, const uint32_t height)
{
  m_width = width;
  m_height = height;
  glViewport(0, 0, width, height);
}

GLuint Renderer::compileShader(GLenum type, const char* source)
{
  const GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  GLint ok = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
  if (!ok)
  {
    char log[1024];
    glGetShaderInfoLog(shader, sizeof(1024), nullptr, log);
    std::cout << log << std::endl;
    glDeleteShader(shader);
    return 0;
  }

  return shader;
}

void Renderer::createPipeline()
{
  const GLuint vertexShader = compileShader(GL_VERTEX_SHADER, VS);
  const GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, FS);

  if (!vertexShader || !fragmentShader)
  {
    return;
  }

  m_program = glCreateProgram();
  glAttachShader(m_program, vertexShader);
  glAttachShader(m_program, fragmentShader);
  glLinkProgram(m_program);

  GLint ok = 0;
  glGetProgramiv(m_program, GL_LINK_STATUS, &ok);
  if (!ok)
  {
    char log[1024];
    glGetProgramInfoLog(m_program, sizeof(log), nullptr, log);
    std::cout << log << std::endl;
    return;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  const float vertexes[] =
  {
    -1, -1, -1,
     1, -1, -1,
     1,  1, -1,
    -1,  1, -1,
    -1, -1,  1,
     1, -1,  1,
     1,  1,  1,
    -1,  1,  1,
  };

  const unsigned indices[] =
  {
    0, 2, 1,   0, 3, 2,
    4, 5, 6,   4, 6, 7,
    0, 4, 7,   0, 7, 3,
    1, 2, 6,   1, 6, 5,
    0, 1, 5,   0, 5, 4,
    3, 7, 6,   3, 6, 2
  };

  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_vbo);
  glGenBuffers(1, &m_ebo);

  glBindVertexArray(m_vao);

  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

  glBindVertexArray(0);
}

}

#include "Engine.h"

#include "render/Mesh.h"
#include "render/Renderer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <chrono>
#include <glad/gl.h>


namespace Graviton
{

namespace
{

void framebufferSizeCallback(GLFWwindow*, const int32_t width, const int32_t height)
{
  glViewport(0, 0, width, height);
}

}

void startEngine(const EngineInitializationParams& params)
{
  if (!glfwInit())
  {
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(params.windowWidth, params.windowHeight, params.windowTitle.c_str(), nullptr, nullptr);
  if (!window)
  {
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
  glfwSwapInterval(1);

  if (!gladLoadGL(glfwGetProcAddress))
  {
    return;
  }

  Renderer renderer(params.windowWidth, params.windowHeight);

  Mesh mesh("test");

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    renderer.draw();

    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

}

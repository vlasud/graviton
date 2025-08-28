#include "Engine.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Graviton
{

static void framebufferSizeCallback(GLFWwindow*, const int32_t width, const int32_t height)
{
  glViewport(0, 0, width, height);
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

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    glClearColor(0.1f, 0.12f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

}

#include "Engine.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Graviton
{

static void framebuffer_size_callback(GLFWwindow*, int w, int h)
{
  glViewport(0, 0, w, h);
}

void startEngine()
{
  if (!glfwInit())
  {
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* win = glfwCreateWindow(800, 600, "GLFW Window", nullptr, nullptr);
  if (!win)
  {
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(win);
  glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
  glfwSwapInterval(1);

  if (!gladLoadGL(glfwGetProcAddress))
  {
    return;
  }

  while (!glfwWindowShouldClose(win))
  {
    glfwPollEvents();

    glClearColor(0.1f, 0.12f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(win);
  }

  glfwDestroyWindow(win);
  glfwTerminate();
}

}

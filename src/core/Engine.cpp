#include "Engine.h"

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

  auto t0 = std::chrono::high_resolution_clock::now();

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    // время
    auto t  = std::chrono::high_resolution_clock::now();
    float s = std::chrono::duration<float>(t - t0).count();

    // Матрицы:
    glm::mat4 model = glm::rotate(glm::mat4(1.0f), s, glm::vec3(0.3f, 1.0f, 0.0f));
    glm::mat4 view  = glm::lookAt(glm::vec3(0, 0, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    glm::mat4 proj  = glm::perspective(glm::radians(60.0f), (float)params.windowWidth/(float)params.windowHeight, 0.1f, 100.0f);

    glm::mat4 mvp = proj * view * model;
    renderer.setMVP(mvp);

    renderer.draw();

    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

}

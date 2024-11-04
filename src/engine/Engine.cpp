#include <graviton/engine/Engine.h>

#include <chrono>
#include <thread>

namespace graviton
{

static void errorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void Engine::init()
{
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
    {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    m_window = std::make_unique<WindowWrapper>(1920, 1080, "Title");

    glfwMakeContextCurrent(&m_window->Get());
    glfwSwapInterval(1);
}

void Engine::run()
{
    while (!glfwWindowShouldClose(&m_window->Get()))
    {
        manageTicksFrequency();
    }
}

void Engine::manageTicksFrequency()
{
    m_gameLoopTickData.currentTickTime = glfwGetTime();

    if (m_gameLoopTickData.isFirstTick)
    {
        m_gameLoopTickData.previousTickTime = m_gameLoopTickData.currentTickTime;
        m_gameLoopTickData.isFirstTick = false;

        tick(0.0);
        return;
    }

    const double deltaTime = m_gameLoopTickData.currentTickTime - m_gameLoopTickData.previousTickTime;
    const double timePerTick = 1.0 / m_gameLoopTickData.maxFps;

    if (deltaTime < timePerTick)
        return;

    m_gameLoopTickData.previousTickTime = m_gameLoopTickData.currentTickTime;

    tick(deltaTime);
}

void Engine::tick(double deltaTime)
{
    char buf[20];
    sprintf(buf, "FPS: %d", static_cast<uint32_t>(1.0 / deltaTime));
    glfwSetWindowTitle(&m_window->Get(), buf);

    glfwSwapBuffers(&m_window->Get());
    glfwPollEvents();
}

}; // graviton


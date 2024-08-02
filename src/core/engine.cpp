#include <core/engine.h>

#include <render/renderer.h>
#include <input/input.h>

#include <chrono>
#include <iostream>
#include <functional>


static void window_resize_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    auto engine = Engine::get();
    engine->renderer->setScreenSize(width, height);
}


Engine* Engine::get()
{
    static Engine* engine = nullptr;
    if (!engine)
        engine = new Engine;
    return engine;
}

Engine::Engine() :
    window(nullptr), renderer(std::make_unique<Renderer>())
{
}

Engine::~Engine()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Engine::is_run_allowed() const
{
    return window;
}

void Engine::run()
{
    if (!is_run_allowed())
        throw std::runtime_error("engine run not allowed");

    double prevTime = glfwGetTime();
    double curTime = prevTime;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        curTime = glfwGetTime();
        double deltaTime = curTime - prevTime;
        prevTime = curTime;

        //scene->act(deltaTime);
        renderer->act(deltaTime);

        glfwSwapBuffers(window);
    }
}

void Engine::init(const EngineInitDesc& init_desc)
{
    if (!glfwInit())
        throw std::runtime_error("glfw init error");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(init_desc.windowSize[0], init_desc.windowSize[1],
        init_desc.title.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("glfw create window error");
    }

    glfwSetWindowSizeCallback(window, window_resize_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);

    //scene = std::make_unique<Scene>();

    renderer->setScreenSize(init_desc.windowSize[0], init_desc.windowSize[1]);
}
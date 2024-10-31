#include <graviton/engine/Engine.h>

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

    m_window = eastl::make_unique<WindowWrapper>(1920, 1080, "Title");

    glfwMakeContextCurrent(&m_window->Get());
    glfwSwapInterval(1);
}

void Engine::run()
{
    while (!glfwWindowShouldClose(&m_window->Get()))
    {
        glfwSwapBuffers(&m_window->Get());
        glfwPollEvents();
    }
}

}; // graviton

// https://github.com/electronicarts/EASTL/blob/master/doc/CMake/EASTL_Project_Integration.md#overloading-operator-new
void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
    return new uint8_t[size];
}

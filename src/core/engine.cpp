#include <core/Engine.h>
#include <render/Renderer.h>

namespace graviton
{

static void windowResizeCallback(GLFWwindow* windowPtr, int width, int height)
{
    glViewport(0, 0, width, height);

    auto engine = Engine::GetInstance();
    engine->m_renderer->setScreenSize(width, height);
}

Engine::Engine() :
    m_windowPtr(nullptr), m_renderer(eastl::make_unique<Renderer>())
{
}

Engine::~Engine()
{
    glfwDestroyWindow(m_windowPtr);
    glfwTerminate();
}

bool Engine::isRunAllowed() const
{
    return m_windowPtr;
}

void Engine::run()
{
    if (!isRunAllowed())
        return;

    double prevTime = glfwGetTime();
    double curTime = prevTime;

    while (!glfwWindowShouldClose(m_windowPtr))
    {
        glfwPollEvents();

        curTime = glfwGetTime();
        double deltaTime = curTime - prevTime;
        prevTime = curTime;

        m_renderer->act(deltaTime);

        glfwSwapBuffers(m_windowPtr);
    }
}

void Engine::init(const EngineInitDescription& initDescription)
{
    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_windowPtr = glfwCreateWindow(initDescription.windowWidth, initDescription.windowHeight,
        initDescription.windowTitle.c_str(), NULL, NULL);

    if (!m_windowPtr)
    {
        glfwTerminate();
        return;
    }

    glfwSetWindowSizeCallback(m_windowPtr, windowResizeCallback);

    glfwMakeContextCurrent(m_windowPtr);
    gladLoadGL(glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);

    m_renderer->setScreenSize(initDescription.windowWidth, initDescription.windowHeight);
}

}; // graviton

// https://github.com/electronicarts/EASTL/blob/master/doc/CMake/EASTL_Project_Integration.md#setting-up-your-code
void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
    return new uint8_t[size];
}

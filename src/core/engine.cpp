#include <core/Engine.h>

#include <render/Renderer.h>
#include <input/Input.h>


static void window_resize_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    auto engine = Engine::GetInstance();
    engine->renderer->setScreenSize(width, height);
}

Engine::Engine() :
    window(nullptr), renderer(eastl::make_unique<Renderer>())
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
        return;

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

void Engine::init(const EngineInitDescription& init_desc)
{
    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(init_desc.m_windowSize[0], init_desc.m_windowSize[1],
        init_desc.m_windowTitle.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwSetWindowSizeCallback(window, window_resize_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);

    //scene = std::make_unique<Scene>();

    renderer->setScreenSize(init_desc.m_windowSize[0], init_desc.m_windowSize[1]);
}

// https://github.com/electronicarts/EASTL/blob/master/doc/CMake/EASTL_Project_Integration.md#setting-up-your-code
void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
	return new uint8_t[size];
}

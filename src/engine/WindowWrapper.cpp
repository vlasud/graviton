#include <graviton/engine/WindowWrapper.h>

namespace graviton
{

WindowWrapper::WindowWrapper(uint32_t width, uint32_t height, eastl::string_view title)
{
    m_window = glfwCreateWindow(width, height, title.data(), NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

WindowWrapper::~WindowWrapper()
{
    glfwDestroyWindow(m_window);
}

GLFWwindow& WindowWrapper::Get() const
{
    return *m_window;
}

}; // graviton

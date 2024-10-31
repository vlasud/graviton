#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <EASTL/string.h>

namespace graviton
{

class WindowWrapper final
{
public:
    WindowWrapper(uint32_t width, uint32_t height, eastl::string_view title);
    ~WindowWrapper();

    GLFWwindow& Get() const;

private:
    GLFWwindow* m_window{nullptr};
};

} // graviton;
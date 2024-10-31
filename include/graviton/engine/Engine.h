#pragma once

#include <graviton/utils/Singleton.h>
#include <graviton/engine/WindowWrapper.h>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <EASTL/unique_ptr.h>

namespace graviton
{

class Engine final : public Singleton<Engine>
{
REGISTER_SINGLETON(Engine)

public:
    void init();
    void run();

private:
    eastl::unique_ptr<WindowWrapper> m_window;
};

}; // graviton

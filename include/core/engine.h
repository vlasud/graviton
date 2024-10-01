#pragma once

#include <render/Renderer.h>
#include <utils/Singleton.h>
#include <core/EngineInitDescription.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <EASTL/string.h>
#include <EASTL/unique_ptr.h>

namespace graviton
{

class Engine final : public Singleton<Engine>
{
public:
    void run();
    void init(const EngineInitDescription& initDescription);

    friend class Singleton<Engine>;
    friend void windowResizeCallback(GLFWwindow* windowPtr, int width, int height);

private:
    Engine();
    ~Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (const Engine&) = delete;
    Engine& operator = (Engine&&) = delete;

    bool isRunAllowed() const;

    GLFWwindow* m_windowPtr;
    eastl::unique_ptr<Renderer> m_renderer;
};

}; // graviton

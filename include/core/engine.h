#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <core/Scene.h>
#include <render/Renderer.h>
#include <utils/Singleton.h>
#include <core/EngineInitDescription.h>
#include <EASTL/string.h>
#include <EASTL/unique_ptr.h>


class Engine final : public Singleton<Engine>
{
public:
    void run();
    void init(const EngineInitDescription &init_desc);

    friend class Singleton<Engine>;
    friend void window_resize_callback(GLFWwindow* window, int width, int height);

private:
    GLFWwindow *window;
    eastl::unique_ptr<Scene> scene;
    eastl::unique_ptr<Renderer> renderer;

    Engine();
    ~Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (const Engine&) = delete;
    Engine& operator = (Engine&&) = delete;

    bool is_run_allowed() const;
};

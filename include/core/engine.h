#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <core/scene.h>
#include <render/renderer.h>
#include <utils/singleton.h>
#include <EASTL/string.h>
#include <EASTL/unique_ptr.h>


struct EngineInitDesc
{
    uint32_t windowSize[2];
    eastl::string title;
};


class Engine final : public Singleton<Engine>
{
public:
    void run();
    void init(const EngineInitDesc &init_desc);

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

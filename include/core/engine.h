#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <core/scene.h>
#include <render/renderer.h>
#include <string>
#include <memory>


struct EngineInitDesc
{
    uint32_t windowSize[2];
    std::string title;
};


class Engine final
{
    GLFWwindow *window;
    std::unique_ptr<Scene> scene;
    std::unique_ptr<Renderer> renderer;

    Engine();
    ~Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (const Engine&) = delete;
    Engine& operator = (Engine&&) = delete;

    bool is_run_allowed() const;

public:

    static Engine* get();

    void run();
    void init(const EngineInitDesc &init_desc);

    friend void window_resize_callback(GLFWwindow* window, int width, int height);
};
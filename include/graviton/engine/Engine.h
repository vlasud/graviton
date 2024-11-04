#pragma once

#include <graviton/utils/Singleton.h>
#include <graviton/engine/WindowWrapper.h>

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <memory>

namespace graviton
{

struct GameLoopTickData
{
    uint32_t maxFps{144};
    double previousTickTime{0.0};
    double currentTickTime{0.0};
    bool isFirstTick{true};
};

class Engine final : public Singleton<Engine>
{
REGISTER_SINGLETON(Engine)

public:
    void init();
    void run();

private:
    void manageTicksFrequency();
    void tick(double deltaTime);

    std::unique_ptr<WindowWrapper> m_window;

    GameLoopTickData m_gameLoopTickData;
};

}; // graviton

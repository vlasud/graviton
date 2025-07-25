#pragma once

namespace graviton {

// Basic engine class declaration
class Engine {
public:
    Engine() = default;
    ~Engine() = default;

    // Initialize the engine
    void initialize();

    // Shutdown the engine
    void shutdown();
};

} // namespace graviton

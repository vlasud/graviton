#pragma once

#include <core/Object.h>

#include <EASTL/string.h>
#include <EASTL/vector.h>

class Scene final
{
    Scene(const Scene&) = delete;
    Scene(Scene&&) = delete;

    Scene& operator = (const Scene&) = delete;
    Scene& operator = (Scene&&) = delete;

    eastl::string name;
    eastl::vector<Object> objectsPool;

public:

    Scene() = default;
    ~Scene();

    void act(double deltaTime);
};

#pragma once

#include <EASTL/string.h>

namespace graviton
{

struct EngineInitDescription
{
    uint32_t windowWidth;
    uint32_t windowHeight;
    eastl::string windowTitle;
};

}; // graviton

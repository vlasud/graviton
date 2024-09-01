#pragma once

#include <EASTL/string.h>
#include <EASTL/array.h>

struct EngineInitDescription
{
    eastl::array<uint32_t, 2> m_windowSize;
    eastl::string m_windowTitle;
};

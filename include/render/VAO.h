#pragma once

#include <EASTL/vector.h>

namespace graviton
{

class VAO
{
public:
    VAO();
    ~VAO();
    void bind();

private:
    uint32_t m_id;
};

}; // graviton

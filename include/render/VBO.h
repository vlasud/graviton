#pragma once

#include <EASTL/vector.h>

namespace graviton
{

class VBO
{
public:
    VBO();
    ~VBO();
    void bind();
    void setData(eastl::vector<float>& data);

private:
    uint32_t m_id;
};

}; // graviton

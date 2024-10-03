#include <render/VBO.h>

#include <glad/gl.h>

namespace graviton
{

VBO::VBO()
{
    glGenBuffers(1, &m_id);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &m_id);
}

void VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VBO::setData(eastl::vector<float>& data)
{
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
}

}; // graviton

#include <render/VAO.h>

#include <glad/gl.h>

namespace graviton
{

VAO::VAO()
{
    glGenVertexArrays(1, &m_id);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_id);
}

void VAO::bind()
{
    glBindVertexArray(m_id);
}

}; // graviton

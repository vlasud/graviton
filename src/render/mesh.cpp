#include <render/Mesh.h>
#include <render/ObjFile.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace graviton
{

BaseMesh::BaseMesh(const eastl::string_view pathToObj, const glm::mat4 transform) :
    m_transform(transform), m_isShouldDraw(true)
{
}

BaseMesh::~BaseMesh()
{
}

void BaseMesh::draw(double deltaTime, uint32_t shader_program_id)
{
}

void BaseMesh::setShouldDraw(bool isShouldDraw)
{
    m_isShouldDraw = isShouldDraw;
}

bool BaseMesh::isShouldDraw() const
{
    return m_isShouldDraw;
}

}; // graviton

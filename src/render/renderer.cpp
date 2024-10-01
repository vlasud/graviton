#include <render/Renderer.h>
#include <render/shader.h>

namespace graviton
{

Renderer::Renderer() :
    m_view(glm::mat4(1)), m_screenWidth(640), m_screenHeight(480),
    m_projection(glm::perspective(45.0f, (float)m_screenWidth / (float)m_screenHeight, 0.1f, 100.0f))
{
}

Renderer::~Renderer()
{
}

void Renderer::setScreenSize(uint16_t width, uint16_t height)
{
    m_screenHeight = height;
    m_screenWidth = width;
}

void Renderer::act(double deltaTime)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawMeshes(deltaTime);
}

void Renderer::addMesh(BaseMesh* meshPtr)
{
    if (!meshPtr)
        return;
}

void Renderer::drawMeshes(double deltaTime)
{

}

}; // graviton

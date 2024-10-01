#pragma once

#include <render/Shader.h>
#include <render/Mesh.h>

#include <EASTL/vector.h>
#include <EASTL/unique_ptr.h>

namespace graviton
{

class Renderer final
{
public:
    Renderer();
    ~Renderer();

    void act(double deltaTime);
    void addMesh(BaseMesh* meshPtr);
    void setScreenSize(uint16_t width, uint16_t height);

private:
    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator = (const Renderer&) = delete;
    Renderer& operator = (Renderer&&) = delete;

    void drawMeshes(double deltaTime);

    glm::mat4 m_view;
    glm::mat4 m_projection;
    uint16_t m_screenWidth;
    uint16_t m_screenHeight; 
    eastl::vector<eastl::unique_ptr<BaseMesh>> m_meshes;
    //eastl::unique_ptr<Shader> m_meshShader;
};

}; // graviton

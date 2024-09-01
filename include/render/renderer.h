#pragma once

#include <render/Shader.h>
#include <render/Mesh.h>
#include <vector>
#include <memory>


class Renderer final
{
    glm::mat4 view;
    glm::mat4 projection;
    uint16_t screenWidth, screenHeight;
    std::vector<std::unique_ptr<BaseMesh>> meshes;
    std::unique_ptr<Shader> meshShader;

    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator = (const Renderer&) = delete;
    Renderer& operator = (Renderer&&) = delete;

    void drawMeshes(double delta_time);

public:

    Renderer();
    ~Renderer();

    void act(double delta_time);
    void addMesh(BaseMesh* mesh);
    void setScreenSize(uint16_t width, uint16_t height);
};
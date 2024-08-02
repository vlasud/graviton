#include <render/renderer.h>
#include <render/shader.h>


Renderer::Renderer() :
    view(glm::mat4(1)), screenWidth(640), screenHeight(480),
    projection(glm::perspective(45.0f, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f))
{
    /*
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
    projection = glm::perspective( 45.0f, (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);

    meshes.push_back(std::make_unique<BaseMesh>("../../../assets/duck.obj"));
    meshes.push_back(std::make_unique<BaseMesh>("../../../assets/fish.obj", glm::translate(glm::mat4(1), glm::vec3(0.5, 0.5, -1))));

    meshShader = std::make_unique<Shader>(std::vector<std::string>{
        "../../../graviton/shaders/test.glsl"
    });
    */
}

Renderer::~Renderer()
{
}

void Renderer::setScreenSize(uint16_t width, uint16_t height)
{
    screenHeight = height;
    screenWidth  = width;
}

void Renderer::act(double delta_time)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawMeshes(delta_time);
}

void Renderer::addMesh(BaseMesh* mesh)
{
    if (!mesh)
        return;
}

void Renderer::drawMeshes(double delta_time)
{
    if (!meshShader)
        return;

    meshShader->use();

    GLuint viewLoc = glGetUniformLocation(meshShader->getProgramId(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    GLuint projectionLoc = glGetUniformLocation(meshShader->getProgramId(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    for (auto& mesh : meshes)
    {
        if (mesh->isShouldDraw())
            mesh->draw(delta_time, meshShader->getProgramId());
    }
}
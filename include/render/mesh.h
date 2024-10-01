#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <EASTL/string.h>
#include <EASTL/vector.h>
#include <EASTL/unique_ptr.h>

namespace graviton
{

class BaseMesh
{
public:
    BaseMesh(const eastl::string_view pathToObj, const glm::mat4 transform = glm::mat4(1));
    virtual ~BaseMesh();

    void setShouldDraw(bool isShouldDraw);
    bool isShouldDraw() const;
    virtual void draw(double deltaTime, uint32_t shaderProgramId);

protected:

    glm::mat4 m_transform;
    bool m_isShouldDraw;

    BaseMesh(const BaseMesh&) = delete;
    BaseMesh& operator = (const BaseMesh&) = delete;
};

}; //graviton

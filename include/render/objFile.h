#pragma once

#include <render/Renderer.h>

#include <EASTL/string.h>
#include <EASTL/vector.h>

namespace graviton
{

class ObjFile
{
public:
    explicit ObjFile(const eastl::string_view pathToFile);
    ~ObjFile();

private:
    eastl::vector<float> m_vertices;
    eastl::vector<float> m_vertexNormals;
};

}; // graviton

#include "Mesh.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#include <iostream>

namespace Graviton
{

Mesh::Mesh(const std::string& pathToObjFile)
{
  loadObj(pathToObjFile);
}

void Mesh::loadObj(const std::string& pathToObjFile)
{
  if (m_vbo)
  {
    glDeleteBuffers(1, &m_vbo);
    m_vbo = 0;
  }

  if (m_ebo)
  {
    glDeleteBuffers(1, &m_ebo);
    m_ebo = 0;
  }

  if (m_vao)
  {
    glDeleteVertexArrays(1, &m_vao);
    m_vao = 0;
  }

  tinyobj::ObjReader reader;

  if (!reader.ParseFromFile(pathToObjFile))
  {
    std::cout << "Failed to load obj: " << reader.Error() << std::endl;
    return;
  }

  const tinyobj::attrib_t& attrib = reader.GetAttrib();
  const std::vector<tinyobj::shape_t>& shapes = reader.GetShapes();

  for (auto& shape : shapes)
  {
    for (auto& index : shape.mesh.indices)
    {
      Vertex& vertex = m_vertices.emplace_back();

      vertex.position =
      {
        attrib.vertices[3 * index.vertex_index + 0],
        attrib.vertices[3 * index.vertex_index + 1],
        attrib.vertices[3 * index.vertex_index + 2],
      };

      if (index.normal_index >= 0)
      {
        vertex.normal =
        {
          attrib.normals[3 * index.normal_index + 0],
          attrib.normals[3 * index.normal_index + 1],
          attrib.normals[3 * index.normal_index + 2],
        };
      }

      if (index.texcoord_index >= 0)
      {
        vertex.texcoord =
        {
          attrib.texcoords[2 * index.texcoord_index + 0],
          attrib.texcoords[2 * index.texcoord_index + 1],
        };
      }
    }
  }

  glGenVertexArrays(1, &m_vao);
  glBindVertexArray(m_vao);

  glGenBuffers(1, &m_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, )
}

}
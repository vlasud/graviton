#include "Mesh.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

namespace Graviton
{

Mesh::Mesh(std::string pathToObjFile)
{
  tinyobj::ObjReader reader;
  reader.ParseFromFile(pathToObjFile);
}


}
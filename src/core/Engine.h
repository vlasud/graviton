#pragma once
#include <cstdint>
#include <string>

namespace Graviton
{

struct EngineInitializationParams
{
  uint16_t windowWidth = 640;
  uint16_t windowHeight = 480;
  std::string windowTitle;
};

void startEngine(const EngineInitializationParams& params);

}

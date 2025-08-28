#pragma once
#include "util/String.h"

#include <cstdint>

namespace Graviton
{

struct EngineInitializationParams
{
  uint16_t windowWidth = 640;
  uint16_t windowHeight = 480;
  uint16_t fpsLimit = 60;
  String windowTitle;
};

void startEngine(const EngineInitializationParams& params);

}

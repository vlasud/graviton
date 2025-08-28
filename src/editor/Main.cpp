#include <Engine.h>

int main()
{
  Graviton::EngineInitializationParams params;
  params.windowTitle = "Graviton engine";

  Graviton::startEngine(params);
  return 0;
}

#pragma once

#include <graviton/utils/Singleton.h>

namespace graviton
{

class Engine final : public Singleton<Engine>
{
REGISTER_SINGLETON(Engine)

public:
    int x;

private:
};

}; // graviton

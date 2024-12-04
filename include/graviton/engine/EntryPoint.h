#pragma once

#include <vector>

namespace graviton
{

using ApplicationArguments = std::vector<const char*>;
int GravitonEntry(graviton::ApplicationArguments);

}; // graviton

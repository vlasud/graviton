#pragma once

#include <EASTL/string.h>
#include <EASTL/vector.h>

namespace graviton
{

void split(const eastl::string_view source, char delimiter, eastl::vector<eastl::string>& out);

}; //graviton

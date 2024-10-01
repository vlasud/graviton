#pragma once

#include <EASTL/string.h>

namespace graviton
{

void readFileContent(const eastl::string_view fileName, eastl::string& out);
void getFileExtension(const eastl::string_view fileName, eastl::string& out);
bool checkFileExtension(const eastl::string_view fileName, const eastl::string_view extension);

}; // graviton

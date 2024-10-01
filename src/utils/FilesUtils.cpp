#include <utils/FilesUtils.h>
#include <utils/StringUtils.h>
#include <cassert>
#include <fstream>


namespace graviton
{

void readFileContent(const eastl::string_view fileName, eastl::string& out)
{

}

void getFileExtension(const eastl::string_view fileName, eastl::string& out)
{
    out.clear();

    if (fileName.empty())
        return;

    const uint32_t lastIndex = fileName.size() - 1;
    uint32_t rightIndex = lastIndex;

    while (rightIndex >= 0)
    {
        if (fileName[rightIndex] == '.')
        {
            out = fileName.substr(rightIndex, lastIndex - rightIndex + 1);
            break;
        }

        --rightIndex;
    }
}

bool checkFileExtension(const eastl::string_view fileName, const eastl::string_view extension)
{
    if (fileName.empty() || extension.empty())
        return false;

    eastl::string fileExtension;
    getFileExtension(fileName, fileExtension);

    return fileExtension == extension.data();
}

}; // graviton

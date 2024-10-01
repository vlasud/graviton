#include <utils/StringUtils.h>

namespace graviton
{

void split(const eastl::string_view source, char delimiter, eastl::vector<eastl::string>& out)
{
    out.clear();

    if (source.empty())
        return;

    uint32_t leftIndex = 0;
    uint32_t rightIndex = 0;
    uint32_t lastIndex = source.size() - 1;

    while (rightIndex <= lastIndex)
    {
        if (source[rightIndex] == delimiter)
        {
            out.emplace_back(source.substr(leftIndex, rightIndex - leftIndex));
            leftIndex = rightIndex + 1;
        }
        else if (rightIndex == lastIndex)
        {
            out.emplace_back(source.substr(leftIndex, rightIndex - leftIndex + 1));
            break;
        }

        ++rightIndex;
    }
}

}; //graviton

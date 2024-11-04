#include <graviton/utils/StringUtils.h>

namespace graviton
{

void splitString(const std::string& in, char delimiter, std::vector<std::string>& out)
{
    out.clear();

    if (in.empty())
        return;

    uint32_t leftIndex = 0;
    uint32_t rightIndex = 0;

    while (rightIndex < in.size())
    {
        const bool isLastIteration = rightIndex == in.size() - 1;

        if (isLastIteration || in[rightIndex] == delimiter)
        {
            if (leftIndex < rightIndex)
            {
                //out.push_back(in.substr(leftIndex, rightIndex));
            }

            leftIndex = rightIndex + 1;
        }

        ++rightIndex;
    }
}

};


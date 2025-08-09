#include <iostream>
#include "../core/util/String.h"

int main(int32_t argc, char** argv)
{
    Graviton::String test = "abc_";

    test = test * 5;

    std::cout << test.c_str() << std::endl;

    return 0;
}
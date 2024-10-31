#include <graviton/engine/Engine.h>





// https://github.com/electronicarts/EASTL/blob/master/doc/CMake/EASTL_Project_Integration.md#overloading-operator-new
void* __cdecl operator new[](size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
    return new uint8_t[size];
}

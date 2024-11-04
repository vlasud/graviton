#include <graviton/engine/EntryPoint.h>
#include <graviton/utils/StringUtils.h>

#include <graviton/core/Vector.h>

#ifdef _WIN32
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    graviton::Vector<int> a;
    graviton::Vector<int> b(a);
    return 0;
}
#endif

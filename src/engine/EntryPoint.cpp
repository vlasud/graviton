#include <graviton/engine/EntryPoint.h>
#include <graviton/utils/StringUtils.h>

#include <graviton/core/Vector.h>

#ifdef _WIN32
#include <windows.h>
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    graviton::ApplicationArguments arguments;
    return graviton::GravitonEntry(arguments);
}
#endif

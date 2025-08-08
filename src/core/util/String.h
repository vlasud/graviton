#pragma once
#include <cstdint>

namespace Graviton
{

class String final
{
public:
    String() = default;
    explicit String(const char*);
    String(const String&);
    String(String&&) noexcept;
    ~String();

    String& operator=(const String&);
    String& operator=(String&&) noexcept;

private:
    char* m_data = nullptr;
    uint32_t m_size = 0u;
    uint32_t m_capacity = 0u;
};

}

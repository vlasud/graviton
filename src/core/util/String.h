#pragma once
#include <cstdint>

namespace Graviton
{

class String final
{
public:
    String() = default;
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    ~String();

    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    String& operator=(const char*);

    String& operator+(const String&);
    String& operator+(const char*);

    String& operator+=(const String&);
    String& operator+=(const char*);

    String& operator*=(int32_t);

    String& operator*(int32_t);

    void clear();
    uint32_t length() const;
    uint32_t capacity() const;
    const char* c_str() const;
    void append(const char*);
    void append(const String&);

private:
    char* allocate(uint32_t size);
    const char* getSafeData() const;

    char* m_data = nullptr;
    uint32_t m_size = 0u;
    uint32_t m_capacity = 0u;
};

}

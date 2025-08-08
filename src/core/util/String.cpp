#include "String.h"

#include <cstring>

namespace Graviton
{

String::String(const char* text)
{
    m_size = strlen(text);
    m_capacity = m_size + 1;
    m_data = new char[m_capacity];
    memset(m_data, 0, m_capacity);
    memcpy(m_data, text, m_size);
}

String::String(const String& string)
{
    m_size = string.m_size;
    m_capacity = m_size + 1;
    m_data = new char[m_capacity];
    memset(m_data, 0, m_capacity);
    memcpy(m_data, string.m_data, m_size);
}

String::String(String&& string) noexcept
{
    m_size = string.m_size;
    m_capacity = string.m_capacity;
    m_data = string.m_data;

    string.m_data = nullptr;
    string.m_size = 0u;
    string.m_capacity = 0u;
}

String::~String()
{
    delete[] m_data;
}

String& String::operator=(const String& string)
{
    m_size = string.m_size;
    m_capacity = m_size + 1;
    m_data = new char[m_capacity];
    memset(m_data, 0, m_capacity);
    memcpy(m_data, string.m_data, m_size);
}

String& String::operator=(String&& string) noexcept
{
}

}

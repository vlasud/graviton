#include "String.h"

#include <algorithm>
#include <cstring>

namespace Graviton
{

String::String(const char* text)
{
    m_size = strlen(text);
    m_capacity = m_size + 1;
    m_data = allocate(m_capacity);
    memset(m_data, 0, m_capacity);
    memcpy(m_data, text, m_size);
}

String::String(const String& string)
{
    m_size = string.m_size;
    m_capacity = m_size + 1;
    m_data = allocate(m_capacity);
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
    if (this == &string)
    {
        return *this;
    }

    delete[] m_data;

    m_size = string.m_size;
    m_capacity = string.m_capacity;
    m_data = allocate(m_capacity);
    memset(m_data, 0, m_capacity);
    memcpy(m_data, string.m_data, m_size);

    return *this;
}

String& String::operator=(String&& string) noexcept
{
    if (this == &string)
    {
        return *this;
    }

    delete[] m_data;

    m_size = string.m_size;
    m_capacity = string.m_capacity;
    m_data = string.m_data;

    string.m_data = nullptr;
    string.m_size = 0u;
    string.m_capacity = 0u;

    return *this;
}

String& String::operator=(const char* text)
{
    delete[] m_data;
    m_size = strlen(text);
    m_capacity = m_size + 1;
    m_data = allocate(m_capacity);
    memset(m_data, 0, m_capacity);
    memcpy(m_data, text, m_size);
    return *this;
}

String& String::operator+(const String& string)
{
    append(string);
    return *this;
}

String& String::operator+(const char* text)
{
    append(text);
    return *this;
}

String& String::operator+=(const String& string)
{
    append(string);
    return *this;
}

String& String::operator+=(const char* text)
{
    append(text);
    return *this;
}

String& String::operator*=(const int32_t value)
{
    if (value <= 0)
    {
        clear();
        return *this;
    }

    if (value == 1)
    {
        return *this;
    }

    const uint32_t newCapacity = std::max(m_size * value + 1, m_capacity);
    char* buffer = allocate(newCapacity);
    memset(buffer, 0, newCapacity);

    for (uint32_t i = 0; i < value; ++i)
    {
        memcpy(buffer + m_size * i, m_data, m_size);
    }

    delete[] m_data;
    m_data = buffer;
    m_size *= value;
    m_capacity = newCapacity;

    return *this;
}

String& String::operator*(const int32_t value)
{
    return this->operator*=(value);
}

void String::clear()
{
    m_size = 0u;
    m_capacity = 0u;
    delete[] m_data;
    m_data = nullptr;
}

uint32_t String::length() const
{
    return m_size;
}

uint32_t String::capacity() const
{
    return m_capacity;
}

const char* String::c_str() const
{
    return getSafeData();
}

void String::append(const char* text)
{
    const uint32_t textLength = strlen(text);

    if (m_size + textLength < m_capacity)
    {
        memcpy(m_data + m_size, text, textLength);
        m_size += textLength;
        return;
    }

    m_capacity = m_size + textLength + 1;
    char* newData = allocate(m_capacity);
    memset(newData, 0, m_capacity);
    memcpy(newData, m_data, m_size);
    memcpy(newData + m_size, text, textLength);
    delete[] m_data;
    m_data = newData;
    m_size += textLength;
}

void String::append(const String& text)
{
    append(text.c_str());
}

char* String::allocate(const uint32_t size)
{
    // TODO: pool allocator?
    return new char[size];
}

const char* String::getSafeData() const
{
    if (m_data && m_capacity > 0)
    {
        return m_data;
    }
    return "";
}

}

#pragma once

#include <stdint.h>
#include <utility>

namespace graviton
{

template<typename T>
class Vector
{
public:
    Vector() = default;

    Vector(const Vector& vector)
    {
        m_size = vector.m_size;
        m_capacity = vector.m_capacity;

        m_data = operator new (sizeof(T) * m_capacity);

        for (uint64_t i = 0; i < m_size; ++i)
            new (&m_data[i]) T(vector[i]);
    }

    Vector(Vector&& vector)
    {
        m_data = vector.m_data;
        m_size = vector.m_size;
        m_capacity = vector.m_capacity;

        vector.m_data = nullptr;
        vector.m_size = 0;
        vector.m_capacity = 0;
    }

    virtual ~Vector()
    {
        clear();
        operator delete (m_data);
    }

    Vector& operator=(const Vector& vector)
    {
        clear();

        m_size = vector.m_size;
        m_capacity = vector.m_capacity;

        operator delete (m_data);
        m_data = operator new (sizeof(T) * m_capacity);

        for (uint64_t i = 0; i < m_size; ++i)
            new (&m_data[i]) T(vector[i]);

        return *this;
    }

    Vector& operator=(Vector&& vector)
    {
        m_data = vector.m_data;
        m_size = vector.m_size;
        m_capacity = vector.m_capacity;

        vector.m_data = nullptr;
        vector.m_size = 0;
        vector.m_capacity = 0;

        return *this;
    }

    T& operator[](uint64_t index) const
    {
        return m_data[index];
    }

    template <typename U>
    void pushBack(U&& value)
    {
        if (m_capacity == m_size)
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);

        new (&m_data[m_size]) T(std::forward<U>(value));
        ++m_size;
    }

    void reserve(uint64_t newCapacity)
    {
        if (newCapacity <= m_capacity)
            return;

        T* newData = static_cast<T*>(operator new (sizeof(T) * newCapacity));

        for (uint64_t i = 0; i < m_size; ++i)
        {
            new (&newData[i]) T(std::move(m_data[i]));
            m_data[i].~T();
        }

        operator delete (m_data);
        m_data = newData;
        m_capacity = newCapacity;
    }

    void clear()
    {
        for (uint64_t i = 0; i < m_size; ++i)
            m_data[i].~T();

        m_size = 0;
    }

    uint64_t size() const
    {
        return m_size;
    }

    T* begin()
    {
        return m_data;
    }

    T* end()
    {
        return m_data + m_size;
    }

private:
    T* m_data{nullptr};
    uint64_t m_size{0u};
    uint64_t m_capacity{0u};
};

}; // graviton

#pragma once

#include <stdint.h>

namespace graviton
{

template<typename T>
class Vector
{
public:
    Vector()
    {

    }

    Vector(const Vector& vector)
    {
        m_data = new T[vector.m_capacity];

        for (uint64_t i = 0; i < vector.m_size; ++i)
        {
            m_data[i] = vector[i];
        }
    }

    Vector(Vector&& vector)
    {
    }

    virtual ~Vector()
    {
        delete m_data;
    }

    void pushBack(const T&)
    {

    }

    T& operator[](uint64_t index) const
    {
        return m_data[index];
    }

private:
    T* m_data{nullptr};
    uint64_t m_size{0u};
    uint64_t m_capacity{ 0u };
};

}; // graviton

#pragma once

#include "Vector.h"

namespace graviton
{

class String
{
public:
    String();
    String(const char*);
    String(const String&);
    String(String&&);
    virtual ~String();

private:

    Vector<char32_t> m_data;
};

}; // graviton

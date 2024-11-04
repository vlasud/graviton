#pragma once

#include <memory>

#define REGISTER_SINGLETON(name)\
    friend class Singleton<name>;\
    name() = default;\
    name(const name&) = default;\
    name(name&&) = default;

namespace graviton
{

template<typename T>
class Singleton
{
public:
    static T& GetInstance()
    {
        if (!s_instance)
            s_instance.reset(new T);

        return *s_instance;
    }

    static void DeleteInstance()
    {
        if (s_instance)
            s_instance.reset();
    }

protected:
    Singleton() = default;
    virtual ~Singleton() = default;

private:
    static std::unique_ptr<T> s_instance;
};

template <typename T>
std::unique_ptr<T> Singleton<T>::s_instance;

}; // graviton

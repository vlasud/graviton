#pragma once

template<typename T>
class Singleton
{
public:
	static T* GetInstance()
	{
		if (!instance)
			instance = new T;
		return instance;
	}

	static void ReleaseInstance()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}

protected:
	Singleton() {}
	virtual ~Singleton() {}

private:
	Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;

	Singleton(const Singleton&&) = delete;
    Singleton& operator = (Singleton&&) = delete;

	static T* instance;
};


template <typename T>
T* Singleton<T>::instance = nullptr;

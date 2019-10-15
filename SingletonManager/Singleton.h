#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
#include <memory>

template <typename T>
class Singleton
{
public:
    ~Singleton()
    {
        if (managedObject)
        {
            delete managedObject;
            managedObject = nullptr;
        }
        std::cout << "dtor Singleton" << std::endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;

    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static const T& GetInstance()
    {
        return *(m_GetInstance()->managedObject);
    }

    static std::unique_ptr<Singleton<T>> AutoDestroy()
    {
        return std::unique_ptr<Singleton<T>>(m_GetInstance());
    }

private:
    Singleton(): managedObject(nullptr) 
    {
        std::cout << "ctor Singleton" << std::endl;
        managedObject = new T();
    }

    static Singleton<T>* m_GetInstance()
    {
        static Singleton<T>* inst = new Singleton<T>();
        return inst;
    }

    std::unique_ptr<Singleton<T>> instancePtr;
    T* managedObject;
};

#endif /* SINGLETON_H_ */

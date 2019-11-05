#ifndef MYMANAGER_H
#define MYMANAGER_H

class MyManager
{
public:
    MyManager()
    { 
        std::cout << "ctor MyManager" << std::endl;
    }
    ~MyManager()
    {
        std::cout << "dtor MyManager" << std::endl;
    }

    void PrintNum(int n) const
    {
        std::cout << "Something: " << n << std::endl;
    }
};

#endif

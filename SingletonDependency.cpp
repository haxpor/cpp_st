/**
 * The order of initialization is preserved within the same initialization.
 * So dependency is there before MySingleton needs to use it.
 */
#include <iostream>
#include <memory>

struct Dependency {
    int dummy;
};

Dependency dd { .dummy=1 };

class MySingleton {
public:
    static MySingleton& instance() {
        static MySingleton inst;
        inst.ddPtr = &dd;
        return inst;
    }
    Dependency* ddPtr;
private:
    MySingleton() { }
    ~MySingleton() { }
};

int main() {
    std::cout << MySingleton::instance().ddPtr->dummy << '\n';
    return 0;
}

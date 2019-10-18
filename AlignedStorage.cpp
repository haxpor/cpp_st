/**
 * Demonstrate usage of std::aligned_storage.
 *
 * It's regarded as aligned data structure to hold stack memory space for a single fixed type.
 * The code follows from the example code as seen in man page of std::aligned_storage but with
 * some modifications, and code comment along the way.
 */
#include <iostream>
#include <memory>
#include <utility>
#include <stdexcept>

// target data to be added and used with StaticVector
struct Widget
{
    int a;
    double b;

    Widget(): a(0), b(0.0) {}
    Widget(int a, double b): a(a), b(b) {}
    ~Widget() { std::cout << "dtor Widget [" << a << ", " << b << "]\n"; }
};

// Static vector of type T in aligned memory space.
template <typename T, std::size_t N>
class StaticVector
{
public:
    template <typename...Args>
    void emplace_back(Args&&... args)
    {
        if (m_size >= N)
            throw std::bad_alloc();

        new (&data[m_size++]) T(std::forward<Args>(args)...);
    }

    // no range checking
    T& operator[](std::size_t i)
    {
        // as the backing data of std::aligned_storage is based on array of unsigned char
        // then we need to do reinterpret_cast
        return reinterpret_cast<T&>(data[i]);
    }

    // with range checking
    T& at(std::size_t i)
    {
        if (i >= m_size)
            throw std::out_of_range("StaticVector<T>[i]: i index is out of range");

        return reinterpret_cast<T&>(data[i]);
    }

    std::size_t size() const
    {
        return m_size;
    }

    ~StaticVector()
    {
        for (std::size_t i=0; i<m_size; ++i)
        {
            // manually call each element's destructor method
            reinterpret_cast<T&>(data[i]).~T();
        }
    }

private:
    // backing data to store objects
    // note that data[] is not of type T but it's unsigned char, and ::type is just refer to
    // the underlying union struct for individual element. Thus we still need to do reinterpret_cast.
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data[N];
    std::size_t m_size = 0;
};

int main()
{
    StaticVector<Widget, 2> sv;
    sv.emplace_back(Widget(1, 2.5));

    Widget& p1 = sv[0];
    std::cout << "p1: " << p1.a << ", " << p1.b << '\n';
    std::cout << "size of StaticVector: " << sv.size() << '\n';

    // directly modify the object
    p1.a = 15;
    std::cout << "p1: " << p1.a << ", " << p1.b << '\n';

    // doesn't cause exception, no range check, so undefined behavior here
    // uncomment to see the effect
    //sv[2];
    // had range check, throw exception
    try
    {
        sv.at(2);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    sv.emplace_back(Widget(2, 100.45));
    Widget& p2 = sv.at(1);
    std::cout << "p2: " << p2.a << ", " << p2.b << '\n';
    std::cout << "size of StaticVector: " << sv.size() << '\n';

    std::cout.flush();

    return 0;
}

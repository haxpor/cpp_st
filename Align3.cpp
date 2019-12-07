/**
 * Summing up for byte alignment for struct.
 *
 * Size of byte alignment for a struct might not equal to its struct size. It's usually equal
 * to the largest scalar size of its member field.
 *
 * In this case, it's 8 bytes for double.
 *
 * Also notice `char b` which occupies 1 byte. Total size is not 33 bytes, but eventually be 40 bytes
 * for 8 bytes alignment (by default without alignment enfocement) as it pads the last 7 bytes more
 * to make it align thus allows accessing to struct in aligned manner.
 *
 * Also this shows various ways to define aligned() to struct definition.
 * You can aligned define it at the time of declaration of variable, or right at the time of definition.
 *
 * Note: declare or define struct to be memory aligned, it is specific to compiler. In this case,
 * specific to gcc. For MSVC, similarly syntax of __declspec(align(bytes)) can be used. Check
 * more detail on their documentation.
 */
#include <iostream>

struct MyElement
{
	float a,b,c,d,e;
	unsigned int f;
    double g;
    char h;
};

#define MEM_ALIGN(bytes) __attribute__((aligned(bytes)))
struct MyElementAligned
{
	float a,b,c,d,e;
	unsigned int f;
} MEM_ALIGN(32);

int main()
{
    std::cout << "unaligned MyElement\n";
    std::cout << "  alignof: " << alignof(MyElement) << '\n';
    std::cout << "  sizeof: " << sizeof(MyElement) << '\n';

    // note: byte requested need to be power of 2
    // 64 is closest to 40
    MEM_ALIGN(64) MyElement alignedS;
    std::cout << "aligned MyElement\n";
    std::cout << "  alignof: " << alignof(alignedS) << '\n';
    std::cout << "  sizeof: " << sizeof(alignedS) << '\n';

    std::cout << "MyElementAligned\n";
    std::cout << "  alignof: " << alignof(MyElementAligned) << '\n';
    std::cout << "  sizeof: " << sizeof(MyElementAligned) << '\n';
    return 0;
}


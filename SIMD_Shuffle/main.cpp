/**
 * Testbed that tries to understand how _mm_shuffle_ps() works.
 */

// this is for SSE
#include <xmmintrin.h>
// this is for SSE2, nontheless to use SSE2, we need to also include SSE header file
#include <emmintrin.h>
#include <iostream>

struct __attribute__((aligned(16))) Vec4 
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        __m128 mmval;
    };

    inline float dot(const Vec4& vec4) const
    {
        return 0.0f;
    }
};

void PrintV(const Vec4& v)
{
    std::cout << std::fixed << v.x << ',' << v.y << ',' << v.z << ',' << v.w << std::endl;
}

int main()
{
    Vec4 v1;
    v1.mmval = _mm_set_ps(4.0f, 3.0f, 2.0f, 1.0f);
    PrintV(v1);

    float f;
    // get the lowest component from vector which is 1.0f in this case
    _mm_store_ss(&f, v1.mmval);
    std::cout << f << std::endl;

    // count index from right to left
    // 3 2 1 0 <----- index
    // 1 2 3 4 <----- element value
    // 2 1 4 3 <----- result from shuffle
    v1.mmval = _mm_shuffle_ps(v1.mmval, v1.mmval, _MM_SHUFFLE(2, 3, 0, 1));
    PrintV(v1);

    // this will print lowest single-precision x-component
    std::cout << _mm_cvtss_f32(v1.mmval) << std::endl;

    return 0;
}

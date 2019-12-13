/**
 * SSE related playground code.
 *
 * Word of advice: better not to combine integer and floating-point operation together, as
 * converting to unsigned integer, or unsigned integer support is not as good as floating-point,
 * although there is __m128i but that is for signed so be careful when working on integer type.
 *
 * Compile with
 *  g++ -std=c++11 SSESimple.cpp -msse2
 */
#include <iostream>

#if defined(__SSE__) || defined(__SSE2__)
#include <emmintrin.h>
#endif

int main()
{
    const unsigned int ARGB = 6554298;
    const float alpha = 0.8f;
    __m128 pixels = _mm_set_ps(
            (ARGB & 0xFF000000) >> 24,
            (ARGB & 0xFF0000) >> 16,
            (ARGB & 0xFF00) >> 8,
             ARGB & 0xFF); // load pixel and include with bit operation
    pixels = _mm_mul_ps(pixels, _mm_set_ps1(alpha));        // multiply with alpha value
    pixels = _mm_min_ps(pixels, _mm_set_ps1(255.0f));       // find min between processed pixel value, and 255.0f, then

    float r[4];
    _mm_store_ps(r, pixels);
    std::cout << r[0] << ", " << r[1] << ", " << r[2] << ", " << r[3] << std::endl;
    return 0;
}

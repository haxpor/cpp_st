/**
 * Testbed using SSE/SSE2 capability to find maximum number from million of number from file.
 *
 * Use dataset.txt as produced by CreateDataset.cpp
 *
 * Note that we opt-out not to use std::vector as it doesn't satisfy us in aligned memory allocation.
 * We opt-in to use a barebone manual approach which taken from my code in krr project. You can see
 * the description in the section noted below.
 *
 * Execute it with
 *  ./a.out < dataset.txt
 */

// this is for SSE
#include <xmmintrin.h>
// this is for SSE2, nontheless to use SSE2, we need to also include SSE header file
#include <emmintrin.h>
#include <iostream>
#include <cassert>

/// - the following code taken from my krr project with slightly modified to satisfy modern c++ a bit especially not using malloc()--
/// - link: https://github.com/abzico/krr
/// generic free memory of N bytes alignment
template <typename T>
void KRR_MEM_delete(T* p)
{
  // convert to byte pointer
  unsigned char* ptr = (unsigned char*)p;

  // grab offset size
  std::size_t offset = *(ptr-1);
  // free (original) whole memory space
  delete[] static_cast<unsigned char*>(ptr - offset);
}

// concept for allocating aligned memory space
// overflow it, then turncate the lower bits
// those two techniques will make sure we have aligned memory
//
// return NULL in case it cannot allocate memory due to out of memory
template <typename T>
T* KRR_MEM_new16(std::size_t elementCount)
{
  // allocate memory 16 bytes (15 bytes for alignment size + 1 byte more to store offset size)
  // this means at worst case, we can possibly waste memory for up to 15 bytes unused to
  // satisfy the memory alignment
  unsigned char* p_original = new unsigned char[elementCount*sizeof(T) + 0x10];

  // if not enough memory
  if (p_original == nullptr)
    return nullptr;

  unsigned char* p = p_original;

  // overflow (1.) then truncate (2.) the memory to guaruntee aligned allocation
  //
  // 1.) 0x10 means we offset upwards by 0x0F bytes for actual target byte alignment + 0x01 byte
  // allocated to store our offset size just before the pointer. Offset upwards like this will
  // make sure we will pass the boundary location in which we will truncate it next.
  //
  // 2.) & ~0x0F means we truncate lower 4 bits, 0x0F comes from 0x10 - 1 in order for its result
  // to be negated with ~ thus ~(00001111) => 11110000, so the memory address always at boundary
  // note: for N byte alignment, we only need to offset the pointer from 0 to (N-1) bytes
  p = reinterpret_cast<unsigned char*>(reinterpret_cast<std::uintptr_t>(p + 0x10) & (~0x0F));
  // store offset size at the byte before the pointer
  *(p-1) = p - p_original;

  return reinterpret_cast<T*>(p);
}
// -- end of code copying from my krr project -- //

float findMax(const float* data, int count)
{
    float max;

    float* nonConstData = const_cast<float*>(data);

    __m128 *f4 = reinterpret_cast<__m128*>(nonConstData);
    __m128 maxValue = _mm_setzero_ps();

    int eindex = count/4;
    for (int i=0; i<eindex; ++i)
    {
        maxValue = _mm_max_ps(maxValue, f4[i]);
    }
    
    // find max value in packed 4 vector first
    // use shuffle
    for (int i=0; i<3; ++i)
    {
        maxValue = _mm_max_ps(maxValue, _mm_shuffle_ps(maxValue, maxValue, (2 << 6) | (1 << 4) | (0 << 2) | 3));
    }

    _mm_store_ss(&max, maxValue);

    // the remainder of the array
    for (; eindex < count; ++eindex)
    {
        if (max < data[eindex])
            max = data[eindex];
    }

    return max;
}

int main()
{
    // turn off synchronize to c-stream, this can improve performance
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    float* nums = KRR_MEM_new16<float>(n);
    if (nums == nullptr)
    {
        std::cout << "Error allocate aligned memory\n";
        exit(1);
    }

    assert(reinterpret_cast<std::uintptr_t>(&nums[0]) % 16 == 0);
    assert(reinterpret_cast<std::uintptr_t>(&nums[1]) - reinterpret_cast<std::uintptr_t>(&nums[0]) == sizeof(float));

    for (int i=0; i<n; ++i)
    {
        std::cin >> nums[i];
    }

    std::cout << std::fixed << findMax(nums, n) << std::endl;

    KRR_MEM_delete<float>(nums);

    return 0;
}

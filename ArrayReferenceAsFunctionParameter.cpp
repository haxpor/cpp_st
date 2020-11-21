/**
 * Demonstrate usage of array reference as function's parameter, and it also works for range-based for loop.
 */
#include <cassert>
#include <iostream>

template <size_t ARRAY_SIZE>
int sumArray(const int (&src_array)[ARRAY_SIZE])
{
	assert(ARRAY_SIZE > 0);

	int total = 0;
	for (int i=0; i<ARRAY_SIZE; ++i)
	{
		total += src_array[i];
	}
	return total;
}

template <size_t ARRAY_SIZE>
int sumArray2(const int (&src_array)[ARRAY_SIZE])
{
	assert(ARRAY_SIZE > 0);

	int total = 0;
	// range-base for loop is possible as array's dimension is preserved as the case for array
	// reference for function's argument here
	for (const int n : src_array)
	{
		total += n;
	}
	return total;
}

int main()
{
	int src_array[] = {1, 2, 3, 4, 5};
	const int sum1 = sumArray(src_array);
	const int sum2 = sumArray2(src_array);
	assert(sum1 == sum2 && "Both summation must be equal");
	return 0;
}

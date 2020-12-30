#include <iostream>
#include <list>
#include <algorithm>
#include <future>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
	for (const auto &i : list)
	{
		ostr << " " << i;
	}
	return ostr;
}

// parallel version, selected to execute computation on new thread minimally
template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
	if (input.empty())
		return input;

	std::list<T> result;
	result.splice(result.begin(), input, input.begin());
	T const& pivot = *result.begin();

	auto divide_point = std::partition(input.begin(), input.end(),
			[&](T const& t) { return t < pivot; });

	std::list<T> lower_part;
	lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

	// only lower part will be computed on new thread asynchronously
	std::future<std::list<T>> new_lower(std::async(&parallel_quick_sort<T>, std::move(lower_part)));
	auto new_higher(parallel_quick_sort(std::move(input)));

	result.splice(result.end(), new_higher);
	result.splice(result.begin(), new_lower.get());
	return result;
}

int main()
{
	// number of elements in the list needs to be large enough to compensate using multithreading to compute faster
	std::list<int> input_list = { -21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5,-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5,-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5,-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5,-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5,-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5,-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5 };
	std::cout << "input list: " << input_list << "\n";
	std::list<int> sort_list = parallel_quick_sort(input_list);
	std::cout << "sorted list: " << sort_list << std::endl;
	return 0;
}

#include <list>
#include <iostream>
#include <iterator>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
	for (const auto &i : list)
	{
		ostr << " " << i;
	}
	return ostr;
}

int main()
{
	std::list<int> input_list = { 1, 3, 2, 7, 4, 60, 25 };
	std::list<int> another_list;

	auto it = input_list.begin();
	std::advance(it, 4);

	// note end-iterator is marked for the end but itself is not included
	another_list.splice(another_list.begin(), input_list, input_list.begin(), it);

	std::cout << another_list << std::endl;
	return 0;
}

#include <iostream>
#include <forward_list>
#include <list>
#include <algorithm>

int main() {

	const auto print_list = [](const auto begin, const auto end) {
		for (auto i = begin; i != end; ++i)
			std::cout << *i << ' ';
		std::cout << '\n';
	};

	std::list<int> fl {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
	print_list(fl.cbegin(), fl.cend());

	// std::sort(fl.begin(), fl.end());
	//
	const auto pivot = std::partition(fl.begin(), fl.end(), [](const auto &a){
				return a < 0;
			});

	print_list(fl.cbegin(), pivot);
	print_list(pivot, fl.cend());

	// partition_copy
}

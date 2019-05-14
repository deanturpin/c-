#include <iostream>
#include <vector>

int main() {

	auto print_size = []<typename T>(std::vector<T> &p){
		std::cout << p.size() << "\n";
	};

	std::vector<double> vec(10);
	print_size(vec);

	std::vector<int> vec2(10);
	print_size(vec2);
}

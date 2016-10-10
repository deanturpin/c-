#include <algorithm>
#include <iostream>
#include <vector>

int main() {

	using namespace std;

	// A sequence to sort
	std::vector<unsigned int> sequence = {
		13, 6, 30, 17, 6, 28, 25, 22, 13, 24, 29, 9, 6, 21, 12, 16, 11, 16, 11, 12,
		1, 31, 3, 15, 12, 10, 18, 11, 13, 28, 10, 28, 21, 5, 27, 22, 12, 26, 24, 8
	};

	// Print sequence
	auto print = [](const auto& s) {
		for_each (s.cbegin(), s.cend(), [](auto &n) { cout << string(n, '-') << endl; });
	};

	print(sequence);

	// Jump to beginning of line?
	// cout << "\x1b[A";

	// Clear screen
	// cout << "\033[2J";

	// usleep(500000);

	return 0;
}


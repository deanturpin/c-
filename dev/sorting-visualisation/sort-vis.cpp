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
	const auto print = [](const auto& s) {

		// Clear screen
		cout << "\033[2J";

		for_each (s.cbegin(), s.cend(),
			[](auto &n) { cout << string(n, '-') << endl; });
	};

	// Fill the screen with an empty list to move the cursor to the bottom
	print(vector<unsigned int>(sequence.size()));
	print(sequence);

	////////////////////
	// Insert sort

	// Define the algorithm
	auto is(sequence);
	auto insertionSort = [&print](auto &is) {

		for (auto i = is.begin(); i != is.end() - 1; ++i) {

			auto now = i;
			auto next = (now + 1);

			if (*now > *next) {

				// Swap element
				auto t = *now;
				*now = *next;
				*next = t;

				// Return to start
				i = is.begin();
			}

			print(is);
		}
	};

	// And call it
	insertionSort(is);

	return 0;
}


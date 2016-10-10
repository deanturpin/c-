#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>

int main() {

	using namespace std;

	// A sequence to sort
	std::vector<unsigned int> sequence = {
		13, 6, 30, 17, 6, 28, 25, 22, 13, 24, 29, 9, 6, 21, 12, 16, 11, 16, 11, 12,
		1, 31, 3, 15, 12, 10, 18, 11, 13, 28, 10, 28, 21, 5, 27, 22, 12, 26, 24, 8
	};

	// Print sequence
	const auto print = [](const auto& s) {

		usleep(500000);

		// Clear screen
		cout << "\033[2J";

		for_each (s.cbegin(), s.cend(),
			[](auto &n) { cout << string(n, '-') << endl; });
	};

	// Fill the screen with an empty list to move the cursor to the bottom
	print(vector<unsigned int>(sequence.size()));
	print(sequence);

	// Sort it
	sort(sequence.begin(), sequence.end());
	print(sequence);

	// Reverse it
	reverse(sequence.begin(), sequence.end());
	print(sequence);

	return 0;
}


#include <algorithm>
#include <iostream>
#include <vector>

// Lambda - anonymous functions
void lambda_functions()
{
	using namespace std;

	vector<int> vec {1, 2, 3};

	// Before
	for (const auto &v:vec)
		cout << v << endl;

	// Increment each element
	for_each(vec.begin(), vec.end(), [](int &n){ ++n; });

	// After
	for (const auto &v:vec)
		cout << v << endl;

	auto square_and_print = [](int n) {cout << n * n << endl;};

	square_and_print(5);
}

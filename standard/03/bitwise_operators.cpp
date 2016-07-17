#include <iostream>

int main()
{
	using namespace std;

	const unsigned int left = 0x0101;
	const unsigned int right = 0x1010;

	// Unmodified
	cout << left << endl;
	cout << right << endl;

	// Bitwise not
	cout << ~left << endl;

	// And, or, xor
	cout << (left & right) << endl;
	cout << (left | right) << endl;
	cout << (left ^ right) << endl;

	// Shift 
	cout << (left << 1) << endl;
	cout << (left >> 1) << endl;

	return 0;
}

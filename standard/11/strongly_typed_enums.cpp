#include <iostream>

void strongly_typed_enums()
{
	using namespace std;

	enum nmb1
	{
		one,
		two
	};

	enum class nmb2
	{
		one,
		two,
		three,
	};

	// OK
	cout << nmb1::one << endl;

	// Error - no known conversion
	// cout << nmb2::one << endl;
}

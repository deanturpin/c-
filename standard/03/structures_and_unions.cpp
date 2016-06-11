#include <iostream>

void structures_and_unions()
{
	using namespace std;

	union A
	{
		int foo;
		char bar[4];

		bool operator==(const A &rhs) const { return foo == rhs.foo; }
	};

	A a;
	a.bar[0] = 0xaa;
	a.bar[1] = 0x55;
	a.bar[2] = 0xaa;
	a.bar[3] = 0x55;

	A b;

	cout << hex << a.foo << endl;
	cout << "Address of a - " << hex << reinterpret_cast<unsigned int>(&a) << endl;

	cout << "Does b equal a? " << boolalpha << (b == a) << endl;
}

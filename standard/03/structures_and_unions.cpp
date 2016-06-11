#include <iostream>

void structures_and_unions()
{
	union A
	{
		int foo;
		char bar[4];
	};

	union A a;
	a.bar[0] = 0xaa;
	a.bar[1] = 0x55;
	a.bar[2] = 0xaa;
	a.bar[3] = 0x55;

	std::cout << std::hex << a.foo << std::endl;
}

#include <iostream>

static int static_global1;
static int static_global2 = 5;

void segments()
{
	static int static_local1;
	static int static_local2 = 4;

	int local_var1;
	int local_var2 = 6;

	using namespace std;

	// Memory limits
	cout << "ram lower 0" << endl;
	cout << "ram upper " << hex << 2 * 1024 * 1024 * 1024 << endl;

	// Static variables
	cout << "static_global1\t" << hex << reinterpret_cast<unsigned int>(&static_global1) << endl;
	cout << "static_global2\t" << hex << reinterpret_cast<unsigned int>(&static_global2) << endl;

	cout << "static_local1\t" << hex << reinterpret_cast<unsigned int>(&static_local1) << endl;
	cout << "static_local2\t" << hex << reinterpret_cast<unsigned int>(&static_local2) << endl;

	cout << "local_var1\t" << hex << reinterpret_cast<unsigned int>(&local_var1) << endl;
	cout << "local_var2\t" << hex << reinterpret_cast<unsigned int>(&local_var2) << endl;

	// Dynamic variables
	int *dynamic_local = new int(4);

	cout << "dynamic_local\t" << hex << reinterpret_cast<unsigned
	int>(dynamic_local) << endl;

	delete dynamic_local;

	// Function
	cout << "function\t" << hex << reinterpret_cast<unsigned int>(&segments) << endl;
}

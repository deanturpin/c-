#include <iostream>

int main() {

	using namespace std;

	// Class to monitor consstruction/destruction
	class B {

		public:
			B() { cout << "B ctor" << endl; }
			~B() { cout << "B dtor" << endl; }
	};

	// Class with no explicit constructors nor destructor
	class A {

		B b;
	};

	// Create some instances
	A a;
	A b(a);
	A c = a;

	return 0;
}

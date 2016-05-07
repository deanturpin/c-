#include <iostream>

// Order of contruction/destruction
void construction_order()
{
	using namespace std;

	class A
	{
		public:
			A() { cout << "A ctor" << endl; }
			~A() { cout << "A dtor" << endl; }
	};

	class B : public A
	{
		public:
			B() { cout << "B ctor" << endl; }
			~B() { cout << "B dtor" << endl; }
	};

	cout << "Static allocation" << endl;
	{
		B b;
	}

	cout << "Dynamic allocation - leak (A has non-virtual destructor)" << endl;
	A* a = new B();
	delete a;
}

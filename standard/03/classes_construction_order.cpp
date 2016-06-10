#include <iostream>

void order()
{
	using namespace std;

	cout << "order" << endl;

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

void overload()
{
	using namespace std;

	cout << "overload" << endl;

	class A
	{
		public:
		void foo() { cout << "foo" << endl; }
	};

	class B : public A
	{
		public:
		void foo() { A::foo(); cout << "bar" << endl; }
	};

	class B b;
	b.foo();
}

// Order of contruction/destruction
void classes_construction_order()
{
	order();
	overload();
}

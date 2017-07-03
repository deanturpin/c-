#include <iostream>

void order()
{

    using namespace std;

    cout << "Order" << endl;

    class A {

    public:
        A() { cout << "A" << endl; }
        ~A() { cout << "~A" << endl; }
    };

    class B : public A {

    public:
        B() { cout << "B" << endl; }
        ~B() { cout << "~B" << endl; }
    };

    cout << "Static allocation" << endl;
    {
        B b;
    }

    cout << "Dynamic allocation - leak (A has non-virtual destructor)" << endl;
    A* a = new B();
    delete a;

    cout << "Array of pointers" << endl;

    A* b = new A[4];

    delete[] b;
}

void overload()
{

    using namespace std;

    cout << "Overload" << endl;

    class A {

    public:
        void foo() { cout << "foo" << endl; }
    };

    class B : public A {

    public:
        void foo() const { cout << "bar" << endl; }
    };

    class B b;
    b.foo();
}

// Order of contruction/destruction
int main()
{

    order();
    overload();

    return 0;
}

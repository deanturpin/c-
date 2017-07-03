#include <iostream>

int main()
{

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

    public:
        // Prefix
        A& operator++()
        {
            cout << "++A" << endl;
            return *this;
        }

        // Postfix
        A& operator++(int)
        {
            cout << "A++" << endl;
            return *this;
        }
    };

    // Create some instances
    cout << "Implicit constructors" << endl;
    {
        A a;
        A b(a);
        A c = a;
    }

    cout << "\nOperator overloading" << endl;
    A d;
    ++d;
    d++;

    return 0;
}

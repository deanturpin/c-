#include <iostream>

namespace pet {

using namespace std;

class animal;
class dog;

class animal {

    const string name = "animal";

public:
    animal() { cout << "+" << name << endl; }
    ~animal() { cout << "-" << name << endl; }

    // explicit
    // animal(const int l) : legs(l) { }
    // animal() { }

    void print() { cout << ">"
                        << "animal" << endl; }
};

class dog : public animal {

    const string name = "dog";

public:
    dog() {}

    // dog() { cout << "+ dog" << endl; }
    // ~dog() { cout << "- dog" << endl; }

    void print() { cout << ">" << name << endl; }
};
}

int main()
{

    using namespace std;

    {
        cout << "\nANIMAL\n"
             << endl;
        pet::animal a;
        a.print();
    }

    {
        cout << "\nDOG\n"
             << endl;
        pet::dog d;
        d.print();
    }

    return 0;
}

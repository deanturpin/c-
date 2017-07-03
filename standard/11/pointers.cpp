#include <iostream>
#include <memory>
#include <string>

namespace wood {
using namespace std;

class Animal {
public:
    Animal(string n)
        : name(n)
    {
        cout << "Animal ctor " << name << endl;
    }

    ~Animal() { cout << "Animal dtor " << name << endl; }

    const string name;
};
}

int main()
{
    using namespace std;
    using namespace wood;

    auto a = unique_ptr<Animal>(new Animal("a"));

    // Using reset
    unique_ptr<Animal> b;
    b.reset(new Animal("b"));
    b.reset();

    // Using release - destructor is not called
    auto c = unique_ptr<Animal>(new Animal("c"));
    c.release();

    return 0;
}

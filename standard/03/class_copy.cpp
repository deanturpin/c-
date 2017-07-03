#include <iostream>

namespace mus {
using namespace std;

class instrument {

public:
    int numberOfStrings;
    bool electric;
    string* name;

    instrument()
    {
        name = new string("instrument");
    }

    instrument(const class instrument& i)
    {
        name = new string(*i.name + " copied");
        numberOfStrings = i.numberOfStrings;
    }

    ~instrument()
    {
        delete name;
    }
};
}

int main()
{

    using namespace std;
    using namespace mus;

    // Create some instruments
    instrument a;
    a.numberOfStrings = 5;

    instrument b(a);

    cout << "a strings " << a.numberOfStrings << endl;
    cout << "a name " << *a.name << endl;
    cout << "b strings " << b.numberOfStrings << endl;
    cout << "b name " << *b.name << endl;

    return 0;
}

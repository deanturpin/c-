#include <iostream>

namespace mus {
using namespace std;

class instrument {

public:
  bool electric;
  string *name;
  unsigned long number_of_strings;

  instrument() { name = new string("instrument"); }

  instrument(const class instrument &i) {
    name = new string(*i.name + " copied");
    number_of_strings = i.number_of_strings;
  }

  ~instrument() { delete name; }
};
}

int main() {

  using namespace std;
  using namespace mus;

  // Create some instruments
  instrument a;
  a.number_of_strings = 5;

  instrument b(a);

  cout << "a strings " << a.number_of_strings << endl;
  cout << "a name " << *a.name << endl;
  cout << "b strings " << b.number_of_strings << endl;
  cout << "b name " << *b.name << endl;

  return 0;
}

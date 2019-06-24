// Pimpl AKA Compiler firewall
// "handle body" pattern

// Separate implementation from interface
// Change implementation without need to recompile

#include <iostream>
#include <memory>

namespace wrk {

using namespace std;

class Employee {

  // Pimpl
  struct Impl {

    Impl(string n) : name(n) { cout << "Impl ctor\n"; }
    ~Impl() { cout << "Impl dtor\n"; }

    string name;
  };

  unique_ptr<Impl> pimpl;

public:
  Employee(string n) : pimpl(new Impl(n)) {}

  string getName() { return pimpl->name; }
};
} // namespace wrk

int main() {

  wrk::Employee e("blah");
  std::cout << "Name is " << e.getName() << '\n';
}

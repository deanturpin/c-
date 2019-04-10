#include <iostream>

int main() {

  using namespace std;

  // Class to monitor construction/destruction
  class B {

  public:
    B() { cout << "B ctor\n"; }
    ~B() { cout << "B dtor\n"; }
  };

  // Class with no explicit constructors nor destructor
  class A {

    B b();

  public:
    // Prefix
    A &operator++() {
      cout << "++A\n";
      return *this;
    }

    // Postfix
    A operator++(int) {
      cout << "A++\n";
      return *this;
    }
  };

  // Create some instances
  cout << "Implicit constructors\n";
  {
    A a;
    [[maybe_unused]] A b(a);
    [[maybe_unused]] A c = a;
  }

  cout << "\nOperator overloading\n";
  A d;
  ++d;
  d++;

  return 0;
}

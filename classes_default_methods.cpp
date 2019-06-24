#include <iostream>

int main() {

  // Class to monitor construction/destruction
  class B {

  public:
    B() { std::cout << "B ctor\n"; }
    ~B() { std::cout << "B dtor\n"; }
  };

  // Class with no explicit constructors nor destructor
  class A {

    B b();

  public:
    // Prefix
    A &operator++() {
      std::cout << "++A\n";
      return *this;
    }

    // Postfix
    A operator++(int) {
      std::cout << "A++\n";
      return *this;
    }
  };

  // Create some instances
  std::cout << "Implicit constructors\n";
  {
    A a;
    [[maybe_unused]] A b(a);
    [[maybe_unused]] A c = a;
  }

  std::cout << "\nOperator overloading\n";
  A d;
  ++d;
  d++;
}

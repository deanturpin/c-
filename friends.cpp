#include <iostream>

class A {
public:
  A() : foo(1) { ; }

private:
  int foo;
  friend class B;
};

class B {
public:
  B() {
    class A a;
    std::cout << "Access A's foo " << a.foo << std::'
';
  }
};

int main() {
  class B b;

  return 0;
}

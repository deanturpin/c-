#include <iostream>
#include <vector>

struct A {

  ~A() {std::cout << "A dtor\n"; }
};

struct B {

  ~B() noexcept(false) {std::cout << "B dtor\n";
    throw std::exception();
  }
};

struct C {

  A a;
  B b;

  ~C() {std::cout << "C dtor\n"; 
  }
};

int main() 

try {

    C c;
    std::cout << sizeof c << '\n';

} catch (std::exception &e) {
    std::cout << "Standard exception " << e.what() << '\n';
  }

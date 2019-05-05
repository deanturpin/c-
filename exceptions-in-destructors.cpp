#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct A {

  void bad() {

    std::cout << "A do bad\n";
    // [[maybe_unused]] std::vector<double> v(-1);
  }

  ~A() { std::cout << "A dtor\n"; }
};

struct B {

  void bad() {

    std::cout << "B do bad\n";
    std::string().at(1);
  }

  ~B() noexcept(false) {
    std::cout << "B dtor\n";
    throw 1;
  }
};

struct C {

  A a;
  B b;

  void bad() try {
    std::cout << "C do bad\n";
    a.bad();
    b.bad();
  } catch (std::exception &e) {
    std::cout << "Caught " << std::quoted(e.what()) << '\n';
  }

  ~C() { std::cout << "C dtor\n"; }
};

int main() try {

  C c;
  c.bad();

} catch (int e) {
  std::cout << "Caught straggler " << e << '\n';
} catch (...) {
  std::cout << "Caught straggler\n";
}

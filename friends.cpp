#include <iostream>
#include <string>

class A {
private:
  std::string name() { return "I am A"; }
  friend class B;
};

class B {
    class A a{};
public:
  B() {
    std::cout << a.name() << '\n';
  }

  std::string get_base() {
	  return a.name();
  }
};

int main() {
  class B b;

  std::cout << b.get_base() << '\n';
}

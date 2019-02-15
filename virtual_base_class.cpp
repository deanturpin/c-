#include <iostream>

struct class1 {
  virtual ~class1() {}
};

struct class2 : virtual class1 {
  virtual void id() {}
  virtual ~class2() {}
};

struct class3 : class1 {};

int main() {

  class1 c1;
  class2 c2;
  class3 c3;
  std::cout << std::hex << std::addressof(c1) << " b\n";
  std::cout << std::hex << std::addressof(c2) << " d\n";
  std::cout << std::hex << std::addressof(c3) << " d\n";
}

#include <iostream>

struct func {

  void operator()() { std::cout << "I am functor\n"; }
};

int main() {

  func f;
  f();
}

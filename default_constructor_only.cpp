#include <iostream>

int main() {

  struct A {
    ~A() {}
  };

  A a;
  A b = a;
  A c(b);

  std::cout << sizeof a << " sizeof a\n";
  std::cout << sizeof b << " sizeof b\n";
  std::cout << sizeof c << " sizeof c\n";
}

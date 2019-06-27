#include <iostream>

int main() {
  int foo = 5;
  int bah = 5;

  // const pointer
  int *const p = &bah;
  *p = 6;

  // Error - can't change the destination
  // p = &foo;

  // const type
  int const *q = &bah;
  q = &foo;

  // Error - can't change the value
  // *q = 6;

  std::cout << "foo " << foo << " bah " << bah << '\n';
  std::cout << "p " << *p << " q " << *q << '\n';

  float f = 3.14;
  float* fp = &f;
  int *ip = reinterpret_cast<int*>(fp);

  std::cout << *fp << "\n";
  std::cout << *ip << "\n";
}

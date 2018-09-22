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

  std::cout << "foo " << foo << " bah " << bah << std::'
'; std::cout << "p " << *p << " q " << *q
            << std::'
';

      return 0;
}

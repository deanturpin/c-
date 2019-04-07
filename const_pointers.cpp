#include <iostream>

int main() {

  // Can change both value and pointer
  int f  = 4;
  int h  = 5;
  int *i = &f;
  std::cout << *i << '\n';

  i = &h;
  std::cout << *i << '\n';

  *i = 6;
  std::cout << *i << '\n';
}

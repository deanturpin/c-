#include <iostream>

// If either operand to a modulus operator is negative the result is
// implementation defined.

int main() {

  std::cout << 1 % 3 << '\n';
  std::cout << 1 % -3 << '\n';
}

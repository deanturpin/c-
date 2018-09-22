#include <iostream>

int main() {

  const unsigned long left = 0x0101;
  const unsigned long right = 0x1010;

  // Unmodified
  std::cout << left << '\n';
  std::cout << right << '\n';

  // Bitwise inversion
  std::cout << ~left << '\n';

  // And, or, xor
  std::cout << (left & right) << '\n';
  std::cout << (left | right) << '\n';
  std::cout << (left ^ right) << '\n';

  // Shift
  std::cout << (left << 1) << '\n';
  std::cout << (left >> 1) << '\n';

  return 0;
}

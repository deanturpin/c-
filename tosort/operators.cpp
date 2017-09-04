/*
if either operand to a modulus operator is negative the result is
implementation defined

In pointer addition and subtraction if both operands and the result do not
point inside the same array (or 1 past the last element of the array) the
result is undefined.
*/

#include <iostream>

void shifty() {

  // assume result printed is 4
  std::cout << sizeof(int) << std::endl;

  int x = 0x1000;

  x = x << 32;

  std::cout << std::hex << x << std::endl; // 0x1000
}

void pointer_arithmetic() {

  // assume result printed is 4
  std::cout << sizeof(int) << std::endl;

  int *x = new int;

  // assume result printed is 0x60000000
  std::cout << x << std::endl;

  std::cout << x + 3 << std::endl;
}

int main() {

  using namespace std;

  const int x = 50 % -7;
  const int y = -50 % 7;
  const int z = -50 % -7;

  // clang 3.8.0-2ubuntu4
  cout << x << endl; // 1
  cout << y << endl; // -1
  cout << z << endl; // -1

  pointer_arithmetic();
  shifty();

  return 0;
}

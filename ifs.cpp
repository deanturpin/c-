#include <iostream>

int main() {
  if (const int blah = 0 == 0)
    std::cout << blah << std::endl;

  return 0;
}

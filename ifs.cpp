#include <iostream>

int main() {
  if (const int blah = 0 == 0)
    std::cout << blah << '\n';

  return 0;
}

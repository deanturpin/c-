#include <iostream>
#include <utility>

int main() {

  int i = 5;
  std::cout << i << '\n';

  int j = std::exchange(i, 6);
  std::cout << j << '\n';
  std::cout << i << '\n';
}

#include <iostream>
#include <vector>

std::vector<int> ints() { return {1, 2, 3, 4, 5}; }

int main() {

  std::vector<int> blah = ints();
  for (const auto &i : blah)
    std::cout << i << '\n';

  return 0;
}

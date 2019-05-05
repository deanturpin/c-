#include <iostream>

int main() {

  // Create lambda to square a parameter
  auto square = [](const int n) { return n * n; };

  int array[] = {1, 2, 3};

  // For each
  for (const auto &a : array)
    std::cout << square(a) << '\n';

  // Non-member
  for (auto i = std::cbegin(array); i != std::cend(array); ++i)
    std::cout << *i << '\n';
}

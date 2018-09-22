#include <iostream>

int main() {

  using namespace std;

  // Create lambda to square a parameter
  auto square = [](const int n) { return n * n; };

  int array[] = {1, 2, 3};

  // For each
  for (const auto &a : array)
    cout << square(a) << '\n';

  // Non-member
  for (auto i = cbegin(array); i != cend(array); ++i)
    cout << *i << '\n';

  return 0;
}

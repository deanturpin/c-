#include <algorithm>
#include <iostream>
#include <vector>

// Lambda - anonymous functions
int main() {

  std::vector<int> vec{1, 2, 3};

  // Before
  for (const auto &v : vec)
    std::cout << v << '\n';

  // Increment each element
  std::for_each(vec.begin(), vec.end(), [](int &n) { ++n; });

  // After
  for (const auto &v : vec)
    std::cout << v << '\n';

  auto square_and_print = [](int n) { std::cout << n * n << '\n'; };
  square_and_print(4);

  int blah = 2;

  // Lambda capture
  auto doubleit = [blah] { return blah * blah; };
  auto doubled = doubleit();
  std::cout << doubled << '\n';

  auto doubleit2 = [blah]() -> double { return blah * blah; };
  auto doubled2 = doubleit2();
  std::cout << doubled2 << '\n';
}

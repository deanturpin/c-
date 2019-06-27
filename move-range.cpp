#include <iostream>
#include <vector>
#include <cassert>

int main() {

  std::vector<int> a{1, 2, 3, 4, 5};
  std::vector<int> b;
  std::vector<int> c;

  // Copy into b
  std::copy(a.begin(), a.end(), std::back_inserter(b));

  // Move into c
  std::move(a.begin(), a.end(), std::back_inserter(c));

  assert(a == b);
  assert(a == c);
}

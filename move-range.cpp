#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int main() {

  std::vector<int> a{1, 2, 3, 4, 5};
  std::vector<int> b, c, d(a.size());

  // Copy into b
  std::copy(a.begin(), a.end(), std::back_inserter(b));

  // Move into c
  std::move(a.begin(), a.end(), std::back_inserter(c));

  // Move backwards into d (from the end...)
  std::move_backward(a.begin(), a.end(), d.end());

  assert(a == b);
  assert(a == c);
  assert(a == d);
}

#include <algorithm>
#include <cassert>
#include <vector>

int main() {

  const std::vector<long> vec = {1, 2, 3, 4, 5, 6};
  const auto count = std::count_if(vec.cbegin(), vec.cend(),
                                   [](const auto &a) { return a < 3; });

  assert(count == 2);
  return 0;
}

#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>

int main() {

  const std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  const auto count = count_if(std::cbegin(vec), std::cend(vec),
                              [](const auto &a) { return a < 3; });

  assert(count == 2);
}

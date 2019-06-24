#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {

  std::vector<long> vec{1, 2, 3, 4, 5};

  std::iota(vec.begin(), vec.end(), 100);

  std::copy(vec.cbegin(), vec.cend(),
            std::ostream_iterator<long>(std::cout, "\n"));
}

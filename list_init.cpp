#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> ints() { return {1, 2, 3, 4, 5}; }

int main() {

  std::vector<int> blah = ints();
  copy(std::cbegin(blah), std::cend(blah),
       std::ostream_iterator<int>(std::cout, "\n"));
}

#include <iostream>
#include <vector>
#include <iterator>

int main() {

  std::cout << "blah";
  endl(std::cout);

  std::vector<int> v{1, 2, 3, 4, 5};
  copy(std::cbegin(v), std::cend(v), std::ostream_iterator<int>(std::cout, "\n"));
}

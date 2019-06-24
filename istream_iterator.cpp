#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  std::ifstream in{"pairs.csv"};
  std::vector<int> vec{std::istream_iterator<int>{in}, {}};

  for (const auto &p : vec)
    std::cout << p << "\n";
}

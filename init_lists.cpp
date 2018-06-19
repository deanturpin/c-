#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  using word = char;

  const std::vector<word> numbers{
      std::istreambuf_iterator<word>(std::ifstream("random.bin").rdbuf()), {}};

  std::cout << numbers.size() << " elements\n";
}
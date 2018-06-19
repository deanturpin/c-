#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {

  // Create container of ascending numbers to write to the file
  std::vector<char> v(20);
  std::iota(std::begin(v), std::end(v), 0);

  // File we're reading from and writing to
  const std::string file_name{"binary.bin"};

  // Write
  std::copy(std::cbegin(v), std::cend(v),
            std::ostreambuf_iterator<char>(std::ofstream(file_name).rdbuf()));

  using word = char;

  // Read
  const std::vector<word> numbers{
      std::istreambuf_iterator<word>(std::ifstream(file_name).rdbuf()), {}};

  std::cout << numbers.size() << " elements\n";
}
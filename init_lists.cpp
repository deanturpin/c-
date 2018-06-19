#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {

  // Create container of ascending numbers to write to the file
  std::vector<int> v(30);
  std::iota(std::begin(v), std::end(v), 0);

  // File we're reading from and writing to
  const std::string file_name{"random.bin"};

  // Write
  std::ofstream out(file_name, std::ios::binary);
  std::copy(std::cbegin(v), std::cend(v), std::ostreambuf_iterator<char>(out));

  out.close();

  using word = char;

  // Read
  std::ifstream in(file_name);
  const std::vector<word> numbers{std::istreambuf_iterator<word>(in), {}};

  std::cout << numbers.size() << " elements\n";
}
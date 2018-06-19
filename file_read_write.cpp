#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

size_t read_chars() {

  using word = char;

  // Create container of ascending numbers to write to the file
  const std::vector<word> v{0, 1, 2, 3, 4};
  const std::string file_name{"ascending.bin"};

  // Write
  std::ofstream out(file_name, std::ios::binary);
  std::copy(std::cbegin(v), std::cend(v), std::ostream_iterator<word>(out));
  out.close();

  // Read
  const std::vector<word> numbers{
      std::istreambuf_iterator<word>(std::ifstream(file_name).rdbuf()), {}};

  return numbers.size();
}

size_t read_doubles() {

  using word = unsigned int;

  // Create container of ascending numbers to write to the file
  std::vector<word> v(30);
  std::iota(std::begin(v), std::end(v), word{});
  const std::string file_name{"ascending.txt"};

  // Write
  std::ofstream out(file_name);
  std::copy(std::cbegin(v), std::cend(v),
            std::ostream_iterator<word>(out, "\n"));
  out.close();

  // Read
  std::vector<word> numbers;
  std::ifstream in(file_name);
  std::copy(std::istream_iterator<word>(in), {}, std::back_inserter(numbers));

  return numbers.size();
}

int main() {

  for (const auto &f : {read_doubles(), read_chars()})
    std::cout << f << " elements\n";
}
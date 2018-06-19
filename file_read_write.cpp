#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void read_chars() {

  // Create container of ascending numbers to write to the file
  const std::vector<char> v{0, 1, 2, 3, 4};
  const std::string file_name{"ascending.bin"};

  // Write
  std::ofstream out(file_name, std::ios::binary);
  std::copy(std::cbegin(v), std::cend(v), std::ostream_iterator<char>(out));
  out.close();

  // Read
  const std::vector<char> numbers{
      std::istreambuf_iterator<char>(std::ifstream(file_name).rdbuf()), {}};

  std::cout << numbers.size() << " elements\n";

  for (const auto &i : numbers)
    std::cout << std::to_string(i) << '\n';
}

void read_doubles() {

  // Create container of ascending numbers to write to the file
  std::vector<double> v(30);
  std::iota(std::begin(v), std::end(v), 0.0);
  const std::string file_name{"ascending.txt"};

  // Write
  std::ofstream out(file_name);
  std::copy(std::cbegin(v), std::cend(v),
            std::ostream_iterator<int>(out, "\n"));
  out.close();

  // Read
  std::vector<double> numbers;

  std::ifstream in(file_name);
  std::copy(std::istream_iterator<double>(in), {}, std::back_inserter(numbers));

  std::cout << numbers.size() << " elements\n";

  for (const auto &i : numbers)
    std::cout << i << '\n';
}

int main() {
  read_doubles();
  read_chars();
}
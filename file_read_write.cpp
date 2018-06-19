#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {

  // Create container of ascending numbers to write to the file
  std::vector<double> v(30);
  std::iota(std::begin(v), std::end(v), 0.0);

  // File we're reading from and writing to
  const std::string file_name{"numbers.txt"};

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
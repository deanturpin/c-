#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

int main() {

  // Create a container of incrementing values
  std::vector<int> blah(1000);
  std::iota(blah.begin(), blah.end(), 0);

  // Randomise it
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(blah.begin(), blah.end(), g);
  std::cout << blah.size() << " values\n";

  // The recursive function
  std::vector<int> res;
  const auto process_frame = [&res, &blah](const auto &begin, const auto &end) {
    if (end < blah.cend())
      res.push_back(std::accumulate(begin, end, 0));

    return res;
  };

  // Recursive string concatentation lambda
  std::function<std::string(int)> string_cat = [&string_cat](const int &c) {
    return c ? "F" + string_cat(c - 1) : "E";
  };

  std::cout << std::quoted(string_cat(20)) << '\n';

  // Create iterators
  const auto b  = blah.cbegin();
  const auto e = std::next(blah.cbegin(), 101);

  // Recursively generate results
  for (const auto &r : process_frame(b, e))
    std::cout << r << '\n';
}

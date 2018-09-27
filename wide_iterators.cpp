#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <sstream>
#include <vector>

int main() {

  // Create test vector
  std::vector<double> a(10);
  std::iota(a.begin(), a.end(), -3.5);

  std::cout << "INPUT\n";
  for (const auto &x : a)
    std::cout << x << '\n';

  const long int filter = 5;

  const auto mean = [](const auto begin, const auto end) {
    return std::accumulate(begin, end, 0.0) / static_cast<double>(filter);
  };

  // Golden (iterative) implementation
  std::vector<double> golden;
  for (auto i = a.cbegin(); i < std::prev(a.cend(), filter); ++i)
    golden.push_back(mean(i, std::next(i, filter)));

  // Dump and test
  const auto dump = [&golden](const auto name, const auto p) {
    assert(p == golden);
    std::cout << name << "\n";
    for (const auto &x : p)
      std::cout << x << '\n';
  };

  // Recursive lambda implementation
  {
    std::vector<double> average;

    using iter = const std::vector<double>::const_iterator &;
    using func = const std::function<void(iter, iter)>;

    func av = [&av, &average, &mean](iter begin, iter end) {
      if (std::distance(begin, end) > filter) {
        average.push_back(mean(begin, std::next(begin, filter)));
        av(std::next(begin), end);
      }
    };

    av(a.cbegin(), a.cend());

    dump("lambda", average);
  }

  // Using strings to propagate values
  const std::function<std::string(const int n)> rec = [&rec](const int n) {
    return n == 0 ? "" : std::to_string(n) + " " + rec(n - 1);
  };

  std::stringstream ss(rec(5));
  const std::vector<double> tokens{std::istream_iterator<double>{ss},
                                   std::istream_iterator<double>{}};

  for (const auto &x : tokens)
    std::cout << x << '\n';
}

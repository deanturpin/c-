#include <iostream>
#include <numeric>
#include <vector>

int main() {

  // Create test vector
  std::vector<double> a(20);
  std::iota(a.begin(), a.end(), -10.1);

  std::cout << "INPUT\n";
  for (const auto &x : a)
    std::cout << x << '\n';

  // Calculate x-point average
  const size_t filter = 5;
  std::vector<double> average;
  for (auto i = a.cbegin(); i < std::prev(a.cend(), filter); ++i)
    average.push_back(std::accumulate(i, std::next(i, filter), 0.0) /
                      static_cast<double>(filter));

  std::cout << "AVERAGES\n";
  for (const auto &x : average)
    std::cout << x << '\n';
}

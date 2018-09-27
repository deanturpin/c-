#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int main() {

  // Create test vector
  std::vector<double> a(10);
  std::iota(a.begin(), a.end(), -3.5);

  std::cout << "INPUT\n";
  for (const auto &x : a)
    std::cout << x << '\n';

  const long int filter = 5;

  // Calculate x-point average
  {
    std::vector<double> average;
    for (auto i = a.cbegin(); i < std::prev(a.cend(), filter); ++i)
      average.push_back(std::accumulate(i, std::next(i, filter), 0.0) /
                        static_cast<double>(filter));

    std::cout << "AVERAGES\n";
    for (const auto &x : average)
      std::cout << x << '\n';
  }

  // Calculate x-point average
  {
    std::vector<double> average;

    using iter = std::vector<double>::const_iterator;
    const std::function<void(iter, iter)> av = [&av, &average](iter begin,
                                                               iter end) {
      if (std::distance(begin, end) > filter) {
        average.push_back(
            std::accumulate(begin, std::next(begin, filter), 0.0) /
            static_cast<double>(filter));
        av(std::next(begin), end);
      }
    };

    av(a.cbegin(), a.cend());

    std::cout << "AVERAGES\n";
    for (const auto &x : average)
      std::cout << x << '\n';
  }
}

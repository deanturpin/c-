#include <iomanip>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>

// A template strategy
struct turbo {

  const std::string name = "turbo_20";

  // Rule of five
  turbo() { std::cout << "turbo() " << std::quoted(name) << "\n"; }
  turbo(const turbo &c) : name(c.name) {}
  turbo(turbo &&) = default;
  turbo &operator=(const turbo &) = default;
  turbo &operator=(turbo &&) = default;
  ~turbo() { std::cout << "\t~turbo() " << std::quoted(name) << "\n"; }

  // Buy
  bool buy(const std::vector<double> &p) const { 
    std::cout << "turbo buy\n";
    return true;
  }

  // Sell
  bool sell(const std::vector<double> &series, const double &buy_price)
  const {
    std::cout << "turbo sell\n";
    return true;
  }
};

// Let's trade
int main() {

  std::vector<turbo> s = {turbo()};

  std::for_each(s.cbegin(), s.cend(), [](const auto &i) {

                const std::vector<double> series {1, 23, 4, 5, 6};
                i.buy(series);
                i.sell(series, 1.0);
                });
}

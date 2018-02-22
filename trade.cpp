#include <iomanip>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>

struct turbo {

  const std::string name = "turbo_20";

  turbo() { std::cout << "turbo()\n"; }
  turbo(const turbo &c) { std::cout << "turbo(const turbo&)\n"; }
  turbo(const turbo &&) { std::cout << "turbo(turbo&&)\n"; }
  turbo &operator=(const turbo &) = delete;
  turbo &operator=(turbo &&) = delete;
  virtual ~turbo() { std::cout << "~turbo()\n"; }

  virtual void buy() const { std::cout << "turbo buy\n"; }
  virtual void sell() const { std::cout << "turbo sell\n"; }
};

struct turbonew : public turbo {

  const std::string name = "turbonew";

  turbonew() { std::cout << "turbonew()\n"; }
  turbonew(const turbonew &c) { std::cout << "turbonew(const turbonew&)\n"; }
  turbonew(const turbonew &&) { std::cout << "turbonew(turbonew&&)\n"; }
  turbonew &operator=(const turbonew &) = delete;
  turbonew &operator=(turbonew &&) = delete;
  virtual ~turbonew() { std::cout << "~turbonewnew()\n"; }

  void buy() const override { std::cout << "turbonew buy\n"; }
};

int main() {

  {
    // not vector
    std::cout << "\n## not vector\n";
    turbo a;
    turbonew b;

    a.buy();
    a.sell();
    b.buy();
    b.sell();

    // vector
    std::cout << "\n## vector\n";
    // std::vector<turbo> s {
    //   turbo(),
    //   turbonew()
    // };

    std::vector<turbo> s;
    s.push_back(a);
    s.push_back(b);

    for (const auto &i : s) {
      i.buy();
      i.sell();
    }

    std::cout << "\n## clear\n";
  }
}

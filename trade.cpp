#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

struct turbo {

  const std::string name = "turbo_20";
  const double threshold = 1.1;

  turbo() { std::cout << "turbo()\n"; }
  turbo(const turbo &c) {
    [[maybe_unused]] auto _c = c;
    std::cout << "turbo(const turbo&)\n";
  }
  turbo(const turbo &&) = delete;
  turbo &operator=(const turbo &) = default;
  turbo &operator=(turbo &&) = default;
  virtual ~turbo() { std::cout << "~turbo()\n"; }

  virtual void buy() const { std::cout << "turbo buy " << threshold << "\n"; }
};

struct turbonew : public turbo {

  const std::string name = "turbonew";
  const double threshold = 2.1;

  turbonew() { std::cout << "turbonew()\n"; }
  turbonew(const turbonew &c) : turbo() {
    static_cast<void>(c);
    std::cout << "turbonew(const turbonew&)\n";
  }
  turbonew(const turbonew &&) = delete;
  turbonew &operator=(const turbonew &) = delete;
  turbonew &operator=(turbonew &&) = default;
  virtual ~turbonew() { std::cout << "~turbonewnew()\n"; }

  void buy() const override {
    std::cout << "turbonew buy " << threshold << "\n";
  }
};

int main() {

  std::cout << "\n## not vector\n";
  {
    turbo a;
    turbonew b;

    a.buy();
    b.buy();
  }

  std::cout << "\n## vector dynamic\n";
  {
    std::vector<std::shared_ptr<turbo>> s{std::make_shared<turbo>(),
                                          std::make_shared<turbonew>()};

    for (const auto &i : s)
      i->buy();
  }
}

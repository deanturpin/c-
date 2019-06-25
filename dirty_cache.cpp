#include <iostream>
#include <string>

struct friendly {
  long data[8]{0, 11, 22, 33, 44, 55, 66, 77};

  virtual std::string name() const { return "friendly"; }
  std::string type() const { return "friendly"; }
  virtual ~friendly() {}
};

struct friendlier : public friendly {
  std::string name() const override { return "friendly"; }
};

friendly a;
static friendly a2;

void routine() {}

int counter = 0;

using type = int;

int main() {

  friendly b;
  static friendly c;
  auto d = new friendly;

  const auto lambda = []() {};
  type values1[]{0, 11, 22, 33, 44, 55, 66, 77, 88, 0, 11, 22, 33, 44, 55};
  type values2[]{0, 11, 22, 33, 44, 55, 66, 77, 88, 0, 11, 22, 33, 44, 55};

  std::cout << std::hex;
  std::cout << std::addressof(a) << " global\n";
  std::cout << std::addressof(a2) << " static 1\n";
  std::cout << std::addressof(main) << " main\n";
  std::cout << std::addressof(b) << " stack\n";
  std::cout << std::addressof(c) << " static 2\n";
  std::cout << d << " heap\n";
  std::cout << std::addressof(routine) << " routine\n";
  std::cout << std::addressof(lambda) << " lambda\n";
  std::cout << std::addressof(values1) << " values1\n";
  std::cout << std::addressof(values2) << " values2\n";
  std::cout << std::addressof(a.data) << " member 1\n";
  std::cout << std::addressof(b.data) << " member 2\n";
  std::cout << std::dec;

  for (auto i = 0ul; i < 8; ++i) {
    static auto x = a.data;
    std::cout << '\t' << *x << '\n';
    ++x;
  }

  for (int j = 0; j < 1e8 * 5; ++j)
    for (int i = 0; i < 8; ++i)
      counter += values1[i] + values2[i];

  return counter;
}

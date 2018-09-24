#include <cassert>
#include <iomanip>
#include <string>

struct a {
  static std::string name;
  const static int version = 1;
  static std::string identity() { return name + std::to_string(version); }
};

std::string a::name = "a";

int main() {

  a _a;
  assert(_a.identity() == "a1");
}

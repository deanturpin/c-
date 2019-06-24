// http://www.cplusplus.com/reference/utility/rel_ops/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

namespace {
using namespace std::rel_ops;

class vector2d {

public:
  int x, y;

  vector2d(int px, int py) : x(px), y(py) {}

  int length() const { return std::sqrt(x * x + y * y); }

  bool operator==(const vector2d &rhs) const {
    return length() == rhs.length();
  }
  bool operator<(const vector2d &rhs) const { return length() < rhs.length(); }
};
} // namespace

int main() {

  vector2d a(10, 10);
  vector2d b(15, 5);

  std::cout << std::boolalpha;
  std::cout << "(a < b) is " << (a < b) << '\n';
  std::cout << "(a > b) is " << (a > b) << '\n';
  std::cout << "(a <= b) is " << (a <= b) << '\n';
  std::cout << "(a >= b) is " << (a >= b) << '\n';
}

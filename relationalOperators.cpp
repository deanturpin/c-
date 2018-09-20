// http://www.cplusplus.com/reference/utility/rel_ops/

#include <cmath>
#include <iostream>
#include <utility>

namespace {
using namespace std::rel_ops;

class vector2d {

public:
  double x, y;

  vector2d(double px, double py) : x(px), y(py) {}

  double length() const { return std::sqrt(x * x + y * y); }

  bool operator==(const vector2d &rhs) const {
    return length() == rhs.length();
  }
  bool operator<(const vector2d &rhs) const { return length() < rhs.length(); }
};
} // namespace

int main() {
  using namespace std;

  vector2d a(10, 10);
  vector2d b(15, 5);

  cout << boolalpha;
  cout << "(a < b) is " << (a < b) << endl;
  cout << "(a > b) is " << (a > b) << endl;
  cout << "(a <= b) is " << (a <= b) << endl;
  cout << "(a >= b) is " << (a >= b) << endl;

  return 0;
}

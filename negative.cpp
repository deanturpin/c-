#include <cmath>
#include <iostream>

// https://en.wikipedia.org/wiki/Double-precision_floating-point_format

int main() {

  std::cout << -0xfffffff << '\n';
  std::cout << -0xffffffff << '\n';

  const unsigned long a = 0u;
  std::cout << -a << '\n';
  std::cout << 0.0 << '\n';
  std::cout << -0.0 << '\n';
  std::cout << signbit(0.0) << '\n';
}

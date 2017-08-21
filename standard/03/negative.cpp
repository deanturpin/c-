#include <cmath>
#include <iostream>

// https://en.wikipedia.org/wiki/Double-precision_floating-point_format

int main() {

  using namespace std;

  cout << -0xfffffff << endl;
  cout << -0xffffffff << endl;

  const unsigned int a = 0u;
  std::cout << -a << std::endl;
  std::cout << 0.0 << std::endl;
  std::cout << -0.0 << std::endl;
  std::cout << boolalpha << (0.0 == 0) << std::endl;
  std::cout << boolalpha << (-0.0 == 0) << std::endl;
  std::cout << signbit(0.0) << std::endl; // Returns a number
}

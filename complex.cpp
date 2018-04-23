#include <complex>
#include <iostream>

int main() {

  using namespace std::complex_literals;

  const std::complex<double> c1 = {1, 0};
  const std::complex<double> c2 = 2i;

  std::cout << c1 << " " << c2 << '\n';

  return 0;
}

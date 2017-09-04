#include <iostream>

template <typename A, typename B> void multiply(A a, B b) {
  const auto tmp = a * b;
  std::cout << tmp << std::endl;
}

int main() {

  const double a = 5.0;
  const int b = -4;
  const unsigned int c = 4;

  multiply(a, b);
  multiply(b, c);

  return 0;
}

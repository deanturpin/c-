#include <iostream>

void narrowing() {
  // Error - narrowing
  // int i {7.3};
  double d{0};

  std::cout << d << std::endl;
}

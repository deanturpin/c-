#include <exception>
#include <iostream>

int main() {
  std::cout << std::uncaught_exceptions() << " uncaught exceptions\n";
}

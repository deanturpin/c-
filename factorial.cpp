#include <functional>
#include <iostream>

// 5! = 5 * 4 * 3 * 2 * 1

int main() {

  using func = std::function<unsigned int(unsigned int)>;

  // Recursive factorial function
  const func factorial = [&factorial](const unsigned int fac) {
    return fac == 1 ? 1 : fac * factorial(fac - 1);
  };

  std::cout << factorial(5) << " factorial\n";
}

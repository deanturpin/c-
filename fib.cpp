#include <assert.h>
#include <functional>
#include <iostream>

// 1, 2, 3/2, 5/3, 8/5, 13/8,
//
// 1 2 3 5 8 13
// 1 1 2 3 5 8

int main() {

  const std::function<int(int)> fib1 = [&fib1](const int &n) constexpr {
    if (n == 0)
      return 0;

    if (n == 1)
      return 1;

    if (n == 2)
      return 1;

    return fib1(n - 1) + fib1(n - 2);
  };

  const std::function<double(double)> fib2 = [&fib2](const int &n) constexpr {
    if (n == 0)
      return 1.0;

    if (n == 1)
      return 1.0;

    if (n == 2.0)
      return 1.0;

    return fib2(n - 2.0) + fib2(n - 3.0) / fib2(n - 1.0) + fib2(n - 2.0);
  };

  assert(fib1(0) == 0);
  assert(fib1(1) == 1);
  assert(fib1(2) == 1);
  assert(fib1(3) == 2);
  assert(fib1(4) == 3);
  assert(fib1(5) == 5);
  assert(fib1(8) == 21);
  // std::cout << fib1(10) << '\n';
  // std::cout << fib2(30) << '\n';
  assert(std::fabs(fib2(20.0), 23026.0) <
         std::numeric_limits<double>::epsilon());
}

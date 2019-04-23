#include <cassert>
#include <functional>
#include <iostream>

// 1, 2, 3/2, 5/3, 8/5, 13/8,
//
// 1 2 3 5 8 13
// 1 1 2 3 5 8

int main() {

  const std::function<int(int)> fib1 = [&fib1](const int &n) {
    if (n == 0)
      return 0;

    if (n == 1)
      return 1;

    if (n == 2)
      return 1;

    return fib1(n - 1) + fib1(n - 2);
  };

  assert(fib1(0) == 0);
  assert(fib1(1) == 1);
  assert(fib1(2) == 1);
  assert(fib1(3) == 2);
  assert(fib1(4) == 3);
  assert(fib1(5) == 5);
  assert(fib1(8) == 21);
}

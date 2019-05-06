#include <iostream>
#include <stack>
#include <cassert>

// 0  1 1 2 3 5 8 13  21  34  55  89

int fibonacci(int n) {

  return n == 0 ? 0
    : n == 1 ? 1
    : n == 2 ? 1
    : fibonacci(n-1) + fibonacci(n-2);
}

int main() {

  assert(fibonacci(0) == 0);
  assert(fibonacci(1) == 1);
  assert(fibonacci(2) == 1);
  assert(fibonacci(3) == 2);
  assert(fibonacci(4) == 3);
  assert(fibonacci(5) == 5);
  assert(fibonacci(6) == 8);
}

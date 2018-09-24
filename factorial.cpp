#include <cassert>
#include <functional>
#include <iostream>

// 5! = 5 * 4 * 3 * 2 * 1 = 120

// Using a fold
//   template <typename... Args>
// 	auto factorial2(Args... args)
// 	{
// 	  return (... + factorial2(args - 1));
// 	}

// Template struct
template <int n> struct factorial3 {
  static const int value = n * factorial3<n - 1>::value;
};
template <> struct factorial3<0> { static const int value = 1; };

// Template function
template <int n> int factorial4() { return n * factorial4<n - 1>(); }
template <> int factorial4<0>() { return 1; }

int main() {

  // Recursive lambda
  using func = const std::function<unsigned int(unsigned int)>;
  func factorial1 = [&factorial1](const int n) {
    return n == 1 ? 1 : n * factorial1(n - 1);
  };
  std::cout << factorial1(5) << " factorial1\n";

  std::cout << factorial3<5>::value << " factorial3\n";
  std::cout << factorial4<5>() << " factorial4\n";

  assert(factorial1(5) == 120);
  assert(factorial3<5>::value == 120);
  assert(factorial4<5>() == 120);

  // enum { blah = factorial4<5>() };
  // static_assert(factorial4<5>() == 120);
}

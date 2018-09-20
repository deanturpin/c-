#include <functional>
#include <iostream>

// 5! = 5 * 4 * 3 * 2 * 1 = 120

// Using a fold
//   template <typename... Args>
// 	auto factorial2(Args... args)
// 	{
// 	  return (... + factorial2(args - 1));
// 	}
//
template <int n> struct factorial3 {
  static const int value = n * factorial3<n - 1>::value;
};

template <> struct factorial3<0> { static const int value = 1; };

int main() {

  using func = std::function<unsigned int(unsigned int)>;

  // Recursive factorial function
  const func factorial1 = [&factorial1](const unsigned int n) {
    return n == 1 ? 1 : n * factorial1(n - 1);
  };

  std::cout << factorial1(5) << " factorial1\n";
  // std::cout << factorial2(5) << " factorial2\n";
  std::cout << factorial3<5>::value << " factorial3\n";
}

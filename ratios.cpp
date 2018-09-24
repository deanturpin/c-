#include <cassert>
#include <iostream>
#include <ratio>

int main() {

  std::cout << "Nano is " << std::nano::num << " / " << std::nano::den << ' '
            << "Value of third is "
            << 1.0 * std::ratio<1, 3>::num / std::ratio<1, 3>::den << '\n';

  const auto test_less =
      std::ratio_less<std::ratio<1, 2>, std::ratio<1, 3>>::value;
  const auto test_greater =
      std::ratio_greater<std::ratio<1, 2>, std::ratio<1, 3>>::value;

  assert(test_less == false);
  assert(test_greater == true);
}

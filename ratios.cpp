#include <iostream>
#include <ratio>

int main() {

  std::cout << "Nano is " << std::nano::num << " / " << std::nano::den << ' '
            << "Value of third is "
            << 1.0 * std::ratio<1, 3>::num / std::ratio<1, 3>::den << '\n';

  std::cout << std::boolalpha
            << std::ratio_less<std::ratio<1, 2>, std::ratio<1, 3>>::value
            << '\n'
            << std::ratio_greater<std::ratio<1, 2>, std::ratio<1, 3>>::value
            << '\n';
}

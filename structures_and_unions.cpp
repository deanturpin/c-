#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>

int main() {

  union A {
    uint32_t foo{};
    std::byte bar[4];

    bool operator==(const A &rhs) const { return foo == rhs.foo; }
  };

  A a;
  a.bar[0] = std::byte(0xaa);
  a.bar[1] = std::byte(0x55);
  a.bar[2] = std::byte(0xab);
  a.bar[3] = std::byte(0x56);

  A b;

  std::cout << "Address of a " << std::addressof(a) << '\n';

  std::cout << std::hex << a.foo << '\n';

  // std::for_each(std::cbegin(a.bar), std::cend(a.bar), [](const auto i){
  //               std::byte _i{i};
  //               std::cout << std::to_integer(_i) << '\n';
  //               });

  std::cout << "Does b equal a? " << std::boolalpha << (b == a) << '\n';
}

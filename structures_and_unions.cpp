#include <iostream>

int main() {

  union A {
    int foo;
    unsigned char bar[4];

    bool operator==(const A &rhs) const { return foo == rhs.foo; }
  };

  A a;
  a.bar[0] = 0xaa;
  a.bar[1] = 0x55;
  a.bar[2] = 0xaa;
  a.bar[3] = 0x55;

  A b;

  std::cout << std::hex << a.foo << '\n';
  std::cout << "Address of a - " << std::hex
            << reinterpret_cast<unsigned long>(&a) << '\n';

  std::cout << "Does b equal a? " << std::boolalpha << (b == a) << '\n';

  return 0;
}

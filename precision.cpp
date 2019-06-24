#include <bitset>
#include <cmath>
#include <iostream>

int main() {

  const float f = float(1) / float(5);
  const double d = double(1) / double(5);

  std::bitset<32> fb(*reinterpret_cast<const unsigned long *>(&f));
  std::bitset<64> fd(*reinterpret_cast<const unsigned long *>(&d));

  std::cout << std::round(f) << "\t" << fb << '\n';
  std::cout << std::round(d) << "\t" << fd << '\n';
}

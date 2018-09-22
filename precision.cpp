#include <bitset>
#include <cmath>
#include <iostream>

int main() {

  using namespace std;

  const float f = float(1) / float(5);
  const double d = double(1) / double(5);

  bitset<32> fb(*reinterpret_cast<const unsigned long *>(&f));
  bitset<64> fd(*reinterpret_cast<const unsigned long *>(&d));

  cout << round(f) << "\t" << fb << ' '; cout << round(d) << "\t" << fd << '
';

      return 0;
}

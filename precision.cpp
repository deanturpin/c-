#include <iostream>
#include <bitset>
#include <cmath>

int main() {

  using namespace std;

  const float f = float(1) / float(5);
  const double d = double(1) / double(5);

  bitset<32> fb(*reinterpret_cast<const unsigned long *>(&f));
  bitset<64> fd(*reinterpret_cast<const unsigned long *>(&d));

  cout << round(f) << "\t" << fb << endl;
  cout << round(d) << "\t" << fd << endl;

  return 0;
}

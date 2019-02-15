#include <cmath>
#include <iostream>

int main() {

  using namespace std;

  cout << isinf(1.0 / 0.0) << ' ';
  cout << isinf(0.0 / 0.0) << '\n';

  cout << isnan(0.0 / 0.0) << '\n';

  cout << isnormal(0.0) << ' ';
  cout << isnormal(-1.0) << '\n';

  cout << fpclassify(-1.0) << '\n';
}

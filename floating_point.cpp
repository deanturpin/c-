#include <cmath>
#include <iostream>

int main() {

  using namespace std;

  cout << isinf(1.0 / 0.0) << ' '; cout << isinf(0.0 / 0.0) << '
';

      cout
       << isnan(0.0 / 0.0) << '
';

      cout
       << isnormal(0.0) << ' '; cout << isnormal(-1.0) << '
';

      cout
       << fpclassify(-1.0) << '
';

      return 0;
}

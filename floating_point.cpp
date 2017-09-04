#include <cmath>
#include <iostream>

int main() {

  using namespace std;

  cout << isinf(1.0 / 0.0) << endl;
  cout << isinf(0.0 / 0.0) << endl;

  cout << isnan(0.0 / 0.0) << endl;

  cout << isnormal(0.0) << endl;
  cout << isnormal(-1.0) << endl;

  cout << fpclassify(-1.0) << endl;

  return 0;
}

#include <iostream>

int main() {

  using namespace std;

  enum nmb1 { one, two };

  enum class nmb2 {
    one,
    two,
    three,
  };

  // OK
  cout << nmb1::one << '\n';

  // Error - no known conversion
  // cout << nmb2::one << '

  return 0;
}

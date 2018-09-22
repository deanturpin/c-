#include <iostream>
#include <vector>

int main() {

  using namespace std;

  // Simple
  try {
    throw 2;
  } catch (int e) {
    cout << "Caught exception " << e << '
';
  }

  try {
    vector<int> vec(-1);
  } catch (exception &e) {
    cout << "Standard exception " << e.what() << '
';
  }

  return 0;
}

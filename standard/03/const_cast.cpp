#include <iostream>

void consty(const int&);

void consty(const int& i) {

  // Ignore that const
  int &j = const_cast<int &>(i);
  j = 0;
}

int main() {

  using namespace std;

  {
    const int i = 1;
    cout << i << endl;
    consty(i);
    cout << i << endl;
  }

  {
    int i = 1;
    cout << i << endl;
    consty(i);
    cout << i << endl;
  }

  return 0;
}

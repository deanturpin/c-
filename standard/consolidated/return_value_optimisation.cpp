#include <iostream>

using namespace std;

struct S {

  S() { cout << "ctor" << endl; }
  S(const S &) { cout << "copy" << endl; }
  S &operator=(const S &) {
    cout << "op=" << endl;
    return *this;
  }
};

struct S getAnS() {

  std::cout << "getAnS" << std::endl;
  return S();
}

int main() {

  std::cout << "\nDefault ctor" << std::endl;
  S s1;

  {
    std::cout << "\nOperator = s1" << std::endl;
    S s2 = s1;

    std::cout << "\nOperator = getAnS" << std::endl;
    S s3 = getAnS();

    std::cout << "\nCopy constructor" << std::endl;
    S s4(s1);
  }

  return 0;
}

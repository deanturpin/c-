#include <iostream>

using namespace std;

struct S {

  S() { cout << "ctor" << ' '; }
  S(const S &) { cout << "copy" << ' '; }
  S &operator=(const S &) {
    cout << "op=" << '\n';
    return *this;
  }
};

struct S getAnS() {

  std::cout << "getAnS\n";
  return S();
}

int main() {

  std::cout << "\nDefault ctor\n";
  S s1;

  {
    std::cout << "\nOperator = s1\n";
    [[maybe_unused]] S s2 = s1;

    std::cout << "\nOperator = getAnS\n";
    [[maybe_unused]] S s3 = getAnS();

    std::cout << "\nCopy constructor\n";
    S s4(s1);
  }
}

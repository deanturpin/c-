#include <iostream>

using namespace std;

struct S {

  S() {
    cout
        << "ctor"
        << ' '; } S(const S &){cout << "copy" << ' '; } S & operator=(const S &){cout << "op=" << '
'; return *this;
  }
};

struct S getAnS() {

  std::cout << "getAnS" << std::'
'; return S();
}

int main() {

  std::cout << "\nDefault ctor"
            << std::'
'; S s1;

  {
    std::cout << "\nOperator = s1"
              << std::'
'; [[maybe_unused]] S s2 = s1;

        std::cout
              << "\nOperator = getAnS"
              << std::'
'; [[maybe_unused]] S s3 = getAnS();

        std::cout
              << "\nCopy constructor" << std::'
'; S s4(s1);
  }

  return 0;
}

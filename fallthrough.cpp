// https://www.youtube.com/watch?v=heTklAyLLRQ

#include <iostream>

void do1();
void do2();

int main() {

  int blah = 1;

  switch (blah) {

  case 1:
    do1();
    [[clang::fallthrough]];
  case 2:
    do2();
  }

  return 0;
}

void do1() { std::cout << "do1\n"; }

void do2() { std::cout << "do2\n"; }

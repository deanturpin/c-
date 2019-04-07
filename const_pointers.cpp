#include <iostream>

int main() {

  {
    // Can change both value and pointer
    int f  = 4;
    int h  = 5;
    int *i = &f;
    std::cout << *i << '\n';

    i = &h;
    std::cout << *i << '\n';

    *i = 6;
    std::cout << *i << '\n';
  }

  {
    // Can change only value
    int f = 4;
    // int h  = 5;
    int *i = &f;
    std::cout << *i << '\n';

    // i = &h;
    // std::cout << *i << '\n';

    *i = 6;
    std::cout << *i << '\n';
  }

  {
    // Can change only pointer
    int f        = 4;
    int h        = 5;
    int const *i = &f;
    // const int * i = &f; // const keyword can also go before the type
    std::cout << *i << '\n';

    i = &h;
    std::cout << *i << '\n';

    // *i = 6;
    // std::cout << *i << '\n';
  }
  {
    // Can change only pointer
    int f        = 4;
    int h        = 5;
    int const *i = &f;
    std::cout << *i << '\n';

    i = &h;
    std::cout << *i << '\n';

    // *i = 6;
    // std::cout << *i << '\n';
  }

  {
    // Can change neither value nor pointer
    int f = 4;
    // int h  = 5;
    int const *const i = &f;
    std::cout << *i << '\n';

    // i = &h;
    // std::cout << *i << '\n';

    // *i = 6;
    // std::cout << *i << '\n';
  }
}

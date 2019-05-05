#include <iostream>

int main() {

  {
    // Can change both value and pointer
    int f = 4;
    int h = 5;
    int *i = std::addressof(f);
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
    int *const i = std::addressof(f);
    std::cout << *i << '\n';

    // i = &h;
    // std::cout << *i << '\n';

    *i = 6;
    std::cout << *i << '\n';
  }

  {
    // Can change only pointer
    int f = 4;
    int h = 5;
    int const *i = std::addressof(f);
    std::cout << *i << '\n';

    i = std::addressof(h);
    std::cout << *i << '\n';

    // *i = 6;
    // std::cout << *i << '\n';
  }

  {
    // Can change neither value nor pointer
    int f = 4;
    // int h  = 5;
    int const *const i = std::addressof(f);
    std::cout << *i << '\n';

    // i = &h;
    // std::cout << *i << '\n';

    // *i = 6;
    // std::cout << *i << '\n';
  }
}

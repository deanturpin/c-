#include <iostream>

extern int w;
extern int x;
extern const int y;
extern const int z;

void print_things() {

  std::cout << w << "\n";
  std::cout << x << "\n";
  std::cout << y << "\n";
  std::cout << z << "\n";
}

#include <iostream>
#include <vector>

int main() {

  int x;
  std::vector<int> z(10);
  int y;

  auto w = new int();

  std::cout << std::hex << std::showbase << std::addressof(x)
            << "\tbefore vector on stack\n"
            << std::addressof(y) << "\tvector declaration\n"
            << reinterpret_cast<unsigned long>(z.data()) << "\tvector storage\n"
            << std::addressof(z) << "\tafter vector on stack\n"
            << std::addressof(w) << "\tpointer on the stack\n"
            << std::addressof(*w) << "\tmem on heap\n";

  delete w;
}

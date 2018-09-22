#include <iostream>

static int static_global1;
static int static_global2 = 5;

void segments() {

  static int static_local1;
  static int static_local2 = 4;

  int local_var1;
  int local_var2 = 6;

  using namespace std;

  // Memory limits
  std::cout << "ram lower 0" << '\n';
  std::cout << "ram upper " << std::hex << 2 * 1024 * 1024 * 1024 << '\n';

  // Static variables
  std::cout << "static_global1\t" << std::hex
            << reinterpret_cast<unsigned long>(&static_global1) << '\n';
  std::cout << "static_global2\t" << std::hex
            << reinterpret_cast<unsigned long>(&static_global2) << '\n';

  std::cout << "static_local1\t" << std::hex
            << reinterpret_cast<unsigned long>(&static_local1) << '\n';
  std::cout << "static_local2\t" << std::hex
            << reinterpret_cast<unsigned long>(&static_local2) << '\n';

  std::cout << "local_var1\t" << std::hex
            << reinterpret_cast<unsigned long>(&local_var1) << '\n';
  std::cout << "local_var2\t" << std::hex
            << reinterpret_cast<unsigned long>(&local_var2) << '\n';

  // Dynamic variables
  int *dynamic_local = new int(4);

  std::cout << "dynamic_local\t" << std::hex
            << reinterpret_cast<unsigned long>(dynamic_local) << '\n';

  delete dynamic_local;

  // Function
  std::cout << "function\t" << std::hex
            << reinterpret_cast<unsigned long>(&segments) << '\n';
}

int main() { segments(); }

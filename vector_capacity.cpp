#include <iostream>
#include <string>
#include <vector>

struct copy_me {

  static int copy_constructor_calls;
  static int constructor_calls;

  copy_me() { ++constructor_calls; }
  copy_me(const copy_me &) { ++copy_constructor_calls; }
};

int copy_me::constructor_calls = 0;
int copy_me::copy_constructor_calls = 0;

int main() {

  std::vector<copy_me> vec;
  // vec.reserve(2049);

  for (int i = 0; i < 2049; ++i)
    vec.push_back(copy_me());

  std::cout << "constructor_calls " << copy_me::constructor_calls << '\n'
            << "copy_constructor_calls " << copy_me::copy_constructor_calls
            << '\n';
}

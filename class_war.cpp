#include <iostream>
#include <vector>

unsigned default_constructor_calls = 0;
unsigned copy_constructor_calls = 0;

struct copy_me {

  copy_me() {
    // TODO - do expensive operation
    ++default_constructor_calls;
  }

  copy_me(const copy_me &) {
    // TODO - do expensive operation
    ++copy_constructor_calls;
  }
};

int main() {

  // Lots of calls to default constructor
  std::vector<copy_me> y;
  for (unsigned j = 0; j < 17; ++j)
    y.push_back(copy_me());

  std::cout << default_constructor_calls << " default constructor calls\n";
  std::cout << copy_constructor_calls << " copy constructor calls\n";
}

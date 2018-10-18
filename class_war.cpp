#include <iostream>
#include <vector>

unsigned default_constructor_calls = 0;
unsigned copy_constructor_calls = 0;

struct copy_me {
  copy_me() { ++default_constructor_calls; }
  copy_me(const copy_me &) { ++copy_constructor_calls; }
};

int main() {

  std::vector<std::vector<copy_me>> x;

  const unsigned width = 4;

  // Create a 2D array of objects
  for (unsigned i = 0; i < width; ++i) {

    // Populate a new row
    std::vector<copy_me> y;
    for (unsigned j = 0; j < width; ++j)
      y.push_back(copy_me()); // Call to copy constructor

    // Store the row
    x.push_back(y);
  }

  std::cout << default_constructor_calls << " default constructor calls\n";
  std::cout << copy_constructor_calls << " copy constructor calls\n";
}

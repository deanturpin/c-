#include <iostream>
#include <string>

int main() {

  try {
    throw(std::string("ball"));
  } catch (std::string name) {
    std::cout << name << " caught\n";
  }
}

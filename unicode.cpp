#include <iostream>

int main() {

  const std::string blah{"\u28ff"};
  std::cout << blah << '\n';
}

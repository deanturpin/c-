#include <iomanip>
#include <iostream>
#include <sstream>

int main() {

  std::stringstream in{R"("Hello there" "What time is it?")"};

  std::string line;
  while (in >> std::quoted(line))
    std::cout << line << '\n';
}

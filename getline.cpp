#include <fstream>
#include <iostream>

int main() {

  std::string line;

  {
    std::fstream in("blah");
    std::cout << "good() - file doesn't exists\n";
    if (in.good())
      while (std::getline(in, line))
        std::cout << line << '\n';

    std::cout << "no good() - file doesn't exists\n";
    while (std::getline(in, line))
      std::cout << line << '\n';
  }

  {
    std::fstream in("getline.cpp");
    std::cout << "good() - file does exists\n";
    if (in.good())
      while (std::getline(in, line))
        std::cout << line << '\n';

    std::cout << "no good() - file does exists\n";
    while (std::getline(in, line))
      std::cout << line << '\n';
  }
}

#include <iostream>
#include <map>
#include <string>

int main() {

  std::multimap<std::string, double> m;

  m.insert({"one", 1});
  m.insert({"one", 1});
  m.insert({"one", 1});
  m.insert({"one", 1});
  m.insert({"two", 2});

  for (const auto &[key, value] : m)
    std::cout << key << ", " << value << '\n';

  const auto i = m.find("one");

  std::cout << "Searching... "
            << (i != m.end() ? "found " + std::to_string(i->second)
                             : "not found")
            << '\n';
}

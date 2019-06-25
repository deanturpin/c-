#include <iostream>
#include <memory>

namespace wood {

class Animal {
public:
  Animal(const std::string n) : name(n) {
    std::cout << "ctor " << name << '\n';
  }

  ~Animal() { std::cout << "\tdtor " << name << '\n'; }

  const std::string name;
};
} // namespace wood

int main() {
  const auto a = std::shared_ptr<wood::Animal>(new wood::Animal("a"));
}

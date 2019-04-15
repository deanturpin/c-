#include <iostream>
#include <vector>

struct R {

  R() { std::cout << "ctor\n"; }
  ~R() { std::cout << "\tdtor\n"; }
};

int main() {

  // Test to check resize really calls the destructors
  std::cout << "create\n";
  std::vector<R> vec(4);

  std::cout << "resize\n";
  vec.resize(vec.size() - 1);

  std::cout << "clear\n";
  vec.clear();

  std::cout << "destroy\n";
}

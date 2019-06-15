#include <string>
#include <vector>
#include <iostream>

void print_permutations(const std::vector<int> &a, const std::vector<int> &b) {

  // If we've extracted all the element then print the result
  if (a.empty()) {
    for (auto i : b)
      std::cout << i << " ";
    std::cout << "\n";
  } else {

    for (size_t i = 0; i < a.size(); ++i) {

      auto _a = a;
      auto _b = b;

      // Move current value to second container
      _b.push_back(a.at(i));
      _a.erase(_a.begin() + i);

      print_permutations(_a, _b);
    }
  }
}

int main() {
  std::vector<int> v{1, 2, 3, 4};
  print_permutations(v, {});
}

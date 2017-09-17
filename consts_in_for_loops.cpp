#include <vector>

// Type your code here, or load an example.
int main() {

  const long blah = 5;
  std::vector<long> vec = { 1, 2, 3, 4, 5 };

  for (auto &i : vec) {
    i += blah;
  }
}

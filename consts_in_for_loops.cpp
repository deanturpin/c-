#include <vector>

int main() {

  const long blah = 5;
  std::vector<long> vec = {1, 2, 3, 4, 5};

  for (auto &i : vec)
    i += blah;
}

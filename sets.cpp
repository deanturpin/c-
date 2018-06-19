#include <iostream>
#include <set>

int main() {

  std::set<std::pair<int, int>> s{
      {1, 2}, {1, 2}, {1, 2}, {3, 2}, {6, 7}, {1, 5}, {1, 5},
  };

  std::cout << s.size() << " elements\n";
  for (const auto &p : s)
    std::cout << p.first << ' ' << p.second << '\n';

  // for (auto &p : s)
  // p.first = 0;
}

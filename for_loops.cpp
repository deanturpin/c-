#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  for (const auto &i : {5, 4, 3})
    std::cout << "iter " << i << '\n';

  std::vector<int> vec = {1, 2, 3};
  std::for_each(vec.begin(), vec.end(), [](auto &a) { ++a; });

  for (const auto &v : vec)
    std::cout << "cont " << v << '\n';

  // Can't do this, tho...
  /*
  int i;
  for (i : vec)
          cout << i << '\n';
  */

  for (size_t i = 0; const auto &x : {1, 2,3, 4, 5})
	  std::cout << i++ << "\t" << x << "\n";
}

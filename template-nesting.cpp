#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename T, template <typename> class CONTAINER>
void printme(CONTAINER<T> x) {
  // std::copy(x.cbegin(), x.cend(), std::ostream_iterator<T>(std::cout, '\n'));

  for (auto i : x)
    std::cout << i << "\n";
}

int main() {

  const std::vector<int> v{1, 2, 3, 4, 5};
  printme(v);

  const std::list<double> l{1, 2, 3, 4, 5};
  printme(l);
}

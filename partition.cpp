#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  // Print a list of things
  const auto print_list = [](const auto begin, const auto end) {
    for (auto i = begin; i != end; ++i)
      std::cout << *i << ' ';
    std::cout << '\n';
  };

  // Declare a collection of unsorted things
  std::forward_list<int> fl{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
  print_list(fl.cbegin(), fl.cend());

  // Partition the collection
  const auto zeropivot = [](const auto &a) { return a < 0; };
  const auto pivot = std::partition(fl.begin(), fl.end(), zeropivot);

  // Print partitions
  print_list(fl.cbegin(), pivot);
  print_list(pivot, fl.cend());

  // Create vector with same data and sort
  std::vector<int> vec(fl.cbegin(), fl.cend());
  std::sort(vec.begin(), vec.end());
  print_list(vec.cbegin(), vec.cend());

  // partition_copy
  decltype(vec) true_list, false_list;
  std::partition_copy(vec.cbegin(), vec.cend(), std::back_inserter(true_list),
                      std::back_inserter(false_list), zeropivot);

  print_list(std::cbegin(true_list), std::cend(true_list));
  print_list(std::cbegin(false_list), std::cend(false_list));
}

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  // Print a list of things
  const auto print_list = [](const auto begin, const auto end,
                             const std::string title = "") {

    if (!title.empty())
      std::cout << title << '\n';

    for (auto i = begin; i != end; ++i)
      std::cout << *i << ' ';
    std::cout << '\n';
  };

  // Declare a collection of unsorted things
  std::forward_list<int> fl{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
  print_list(fl.cbegin(), fl.cend(), "Forward list");

  // Partition the collection
  const auto zeropivot = [](const auto &a) { return a < 0; };
  const auto pivot = std::partition(fl.begin(), fl.end(), zeropivot);

  // Print partitions
  print_list(fl.cbegin(), pivot, "Forward list partition 1");
  print_list(pivot, fl.cend(), "Forward list partition 2");

  // Create vector with same data and sort
  std::vector<int> vec(fl.cbegin(), fl.cend());
  std::sort(vec.begin(), vec.end());
  print_list(vec.cbegin(), vec.cend(), "Sorted vector");

  // Partition copy
  decltype(vec) true_list, false_list;
  std::partition_copy(vec.cbegin(), vec.cend(), std::back_inserter(true_list),
                      std::back_inserter(false_list), zeropivot);

  print_list(std::cbegin(true_list), std::cend(true_list), "Vector partion 1");
  print_list(std::cbegin(false_list), std::cend(false_list),
             "Vector partion 2");

  // Stable partion - in place
  std::vector<int> vec2(fl.cbegin(), fl.cend());
  std::stable_partition(vec2.begin(), vec2.end(), zeropivot);
  print_list(std::cbegin(vec2), std::cend(vec2), "Stable partition");
}

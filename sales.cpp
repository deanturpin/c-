#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int max_items(std::vector<int> items, const int k) {

  std::cout << items.size() << " items, " << k << " budget\n";

  if (items.empty())
    return 0;

  std::vector<int> results;

  for (size_t i = 0; i < items.size(); ++i) {

    std::cout << "trying index " << i << "\n";

    const auto val = items.at(i);

    // If we've blown our budget then skip to next
    if (val > k)
      results.push_back(0);
    else {
      // Otherwise... create copy of list
      auto _items = items;

      // Remove the current item
      _items.erase(_items.begin() + i);

      // Push back 1 greater than the results of recursing on the remainder
      results.push_back(1 + max_items(_items, k - val));
    }
  }

  // return results.empty() ? 0 : *std::max_element(results.begin(),
  // results.end());
  return *std::max_element(results.begin(), results.end());
}

int main() {

  std::vector<int> items{1, 5, 70, 8, 4, 2};

  assert(max_items(items, 1) == 1);
  assert(max_items(items, 2) == 1);
  assert(max_items(items, 3) == 2);
  assert(max_items(items, 4) == 2);
  assert(max_items(items, 5) == 2);
  assert(max_items(items, 6) == 2);
  assert(max_items(items, 7) == 3);
}

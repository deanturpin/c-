#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main() {

  // Create collection of things
  std::vector<int> v(10);
  std::fill(std::begin(v), std::end(v), 1);

  // Push some extra things back
  std::fill_n(std::back_inserter(v), 10, 3);

  // Report things
  std::copy(std::begin(v), std::end(v),
            std::ostream_iterator<int>(std::cout, "\n"));

  std::mt19937 rng; // default constructed, seeded with fixed seed
  std::generate_n(
      std::ostream_iterator<std::mt19937::result_type>(std::cout, "\n"), 5,
      std::ref(rng));
}

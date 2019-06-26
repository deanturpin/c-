#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <list>
#include <iomanip>

template <typename T> void print_permutations(const T &a, const T &b) {

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

std::string perms(const int n) {

  if (n == 0)
    return "\n";

  return std::to_string(n) + perms(n - 1);
}

std::string perm_str(std::string s) {
  return s.empty() ? "\n" : perm_str(s.substr(1)) + s[0];
}

std::string bin_tree(const int n) {
  if (n < 1)
    return "x\n";

  std::stringstream v;

  v << "L" << n << bin_tree(n - 1)
    << "M" << n << bin_tree(n - 1)
    << "R" << n << bin_tree(n - 1);

  // TODO - ostream, constexpr

  return v.str();
}

// template <typename T, template <typename> class CONT>
// void operator<<=(T &x, CONT<T> &xs) {
//   x = xs.front();
//   xs.pop_front();
// }
// 
// template <typename T, template <typename> class CONT>
// CONT<T> operator+(CONT<T> a, const T &b) {
// 
//   a.push_back(b);
//   return a;
// }

// template <typename T, template <typename> class CONTAINER>
// CONTAINER<CONTAINER<T>>
//   get_permutations(CONTAINER

std::string perm_list(const std::list<int> &x) {

  // Create list of iterators into the list
  auto it = x.begin();
  std::list<decltype(it)> its;

  for (auto i = x.begin(); i != x.end(); ++i)
    its.push_back(i);

  // for (auto i : its)
  //   std::cout << reinterpret_cast<uint64_t*>(i) << "\n";

  return std::to_string(x.size()) + "\n";
}

int main() {
  std::cout << perms(4);
  std::cout << perm_str("1234") << "\n\n";
  std::cout << bin_tree(3);
  std::cout << "\n\nPERM LIST\n" << perm_list({1, 2, 3, 4});
}

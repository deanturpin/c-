#include <iostream>
#include <string>
#include <vector>
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

// template <class T>
// class alist : public std::list {
// 
// };

// template <class T>
// std::list<T>::operator+(T a, std::list<T> &b) {
// std::alist<T>& std::alist<T>::operator+(T a) {
  // this->push_front(a);
//   return this;
// }

template <typename T>
std::list<T> operator+(std::list<T> a, std::list<T> b) {

  a.merge(b);
  return a;
}

// template <typename T>
// std::list<T> operator+(T &a, std::list<T> &b) {
// 
//   b.push_front(a);
//   return b;
// }

template <typename T, template <typename> class CONT>
CONT<T> operator+(CONT<T> a, const T &b) {

  a.push_back(b);
  return a;
}

std::string perm_list(std::list<int> x) {

  const std::list<int> l{1, 2, 3, 4};
  const std::list<int> r{1, 2, 3, 4};
  std::vector<double> m{1, 2, 3, 4};
  m.reserve(m.size() * 10);

  x = l + r;
  x = r + 1;

  m + 1.0;

  return std::to_string(x.size()) + "\n";
}

int main() {
  std::cout << perms(4);
  std::cout << perm_str("1234") << "\n\n";
  std::cout << bin_tree(3);
  std::cout << "\n\nPERM LIST\n" << perm_list({1, 2, 3, 4});
}

#include <iostream>
#include <list>

auto main() -> int {

  /*
   If you try to make the type const int the compiler fails thus:

/usr/bin/../lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8/bits/stl_list.h:575:7:
error: static_assert failed due to requirement 'is_same<typename remove_cv<const
int>::type, const int>::value' "std::list must have a non-const, non-volatile
value_type"
static_assert(is_same<typename remove_cv<_Tp>::type, _Tp>::value,
*/

  std::list<const int> v{1, 23, 3, 4, 5, 6};
  std::cout << v.size() << " size\n";
}

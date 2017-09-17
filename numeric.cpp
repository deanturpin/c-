#include <iostream>
#include <numeric>
#include <vector>

int main() {

  using namespace std;

  vector<long> vec = {1, 2, 3, 4, 5};

  iota(vec.begin(), vec.end(), 100);

  copy(vec.cbegin(), vec.cend(), ostream_iterator<long>(cout, "\n"));
}

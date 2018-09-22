#include <iostream>
#include <ratio>

int main() {

  using namespace std;

  cout
      << "Nano is " << nano::num << " / " << nano::den
      << ' '; cout << "Value of third is " << 1.0 * ratio<1, 3>::num / ratio<1, 3>::den << '
';
      // cout << "Ratio add " << 1.0 * ratio_add(ratio<1,3>, ratio<1,3>)::den <<
      // '
';

      return 0;
}

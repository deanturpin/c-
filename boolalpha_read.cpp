#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {

  using namespace std;
  cout << "main" << endl;

  const std::string name("/tmp/blah.txt");

  std::string one = "one";
  double two = 1.123456789;
  bool three = false;
  bool four = true;

  cout << "OUT\t" << std::setprecision(10) << one << " "
    << two << " "
    << std::boolalpha << three << " "
    << four << "\n";

  ofstream out(name);
  out.precision(10);
  out << one << " "
    << two << " "
    << std::boolalpha << three << " "
    << four << "\n";
  out.close();

  // Don't need to set precision on way in
  ifstream in(name);
  in >> one >> two >> three >> four;

  cout << "IN\t" << std::setprecision(10) << one << " "
    << two << " "
    << std::boolalpha << three << " "
    << four << "\n";
}

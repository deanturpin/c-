#include <iostream>
#include <fstream>
#include <string>

int main() {

  using namespace std;
  cout << "main" << endl;

  const std::string name("/tmp/blah.txt");

  std::string one = "one";
  double two = 2;
  bool three = false;
  bool four = true;

  ofstream out(name);
  out << one << " "
    << two << " "
    << std::boolalpha << three << " "
    << four << "\n";
  out.close();

  ifstream in(name);
  in >> one >> two >> three >> four;

  cout << one << " "
    << two << " "
    << std::boolalpha << three << " "
    << four << "\n";
}

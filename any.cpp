#include <vector>
#include <iostream>
#include <experimental/any>

int main() {

  std::vector<std::experimental::any> martini(10);

  const std::experimental::any undefined;

  martini.at(5) = 1.0;
  martini.at(6) = "time";
  martini.at(7) = "place";
  martini.at(8) = "where";

  return 0;
}

#include <vector>
#include <iostream>
#include <experimental/any>

int main() {

  std::vector<std::experimental::any> martini(10);

  const std::experimental::any undefined;
  // double blah = std::experimental::make_any();

  martini.at(5) = 1.0;
  martini.at(6) = "time";
  martini.at(7) = "place";
  martini.at(8) = "where";

    // simple example 
    /*
 
    auto a = std::any(12);
 
    std::cout << std::any_cast<int>(a) << '\n'; 
 
    try {
        std::cout << std::any_cast<std::string>(a) << '\n';
    }
    catch(const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }
 
    // advanced example
 
    a = std::string("hello");
 
    auto& ra = std::any_cast<std::string&>(a); //< reference
    ra[1] = 'o';
 
    std::cout << "a: " << std::any_cast<const std::string&>(a) << '\n'; //< const reference
 
    auto b = std::any_cast<std::string&&>(a); //< rvalue reference (no need for std::move)
 
    // Note, 'b' is a move-constructed std::string, 'a' is now empty
 
    std::cout << "a: " << *std::any_cast<std::string>(&a) //< pointer
        << "b: " << b << '\n';
  */

  return 0;
}

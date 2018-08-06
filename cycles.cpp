#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {

  const std::vector<std::string> test_cases = {
      /*
      "0___1___2___3___4___5___6___7___8___9___"
      */
      "-___-___-___-___-___-___-___-___-___-___",
      "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_",
      "__________-----------------------_______"};

  // 0b0000'1000'1000
  //
  const std::vector<std::bitset<20>> test{
      0b1000'1000'1000'1000'1000, 0b0001'1111'1111'1100'1000,
      0b1010'1010'1010'1010'1010, 0b0000'0010'0000'0000'1000,
  };

  std::cout << test_cases.size() << " test cases\n\n";

  // Variable shared by both readers
  bool reg = false;

  // Low frequency reader
  const auto low_frequency_reader = [&reg]() {

    // Local copy of the register
    static auto reported_value = reg;

    if (reg)
      reported_value = true;

    // Report change
    std::cout << reported_value;

    // Clear local copy
    reported_value = false;
  };

  // High frequency reader
  const auto high_frequency_reader = [&reg](const auto r) {
    // Just copy the value passed in
    reg = r == '-' ? true : false;
  };

  // Iterate over all test cases
  for (const auto &test : test_cases) {

    unsigned int iteration = 0;
    for (const auto &hw_read : test) {

      // High frequency reader
      high_frequency_reader(hw_read);

      // Low frequency reader
      if (!(iteration++ % 5))
        low_frequency_reader();
    }

    std::cout << "\ntest complete\n";
  }
}

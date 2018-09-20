#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {

  // A test consists of a pair of input and output bitsets, the low frequency
  // reader runs first
  const std::vector<std::tuple<std::string, std::string, std::string>>
      test_cases{
          // 0123|0123|0123|0123|0123|  expected actual
          {"-------------------------", "-----", ""},
          {"_________________________", "_____", ""},
          {"_____-----------_________", "_---_", ""},
          {"___________--------------", "__---", ""},
          {"-_-_-_-_-_-_-_-_-_-_-_-_-", "-----", ""},
          // 0123|0123|0123|0123|0123|
      };

  std::cout << test_cases.size() << " test cases\n";

  // Iterate over each test pair
  for (auto &[input, expected, actual] : test_cases) {

    const auto high = '-';
    const auto low = '_';

    bool transition_detected = false;
    auto previous_state = low;

    for (const auto &v : {input, expected, actual})
      std::cout << v << '\n';

    size_t high_freq_index = 0;

    for (const auto &state : input) {

      // Hight frequency reader records state changes
      if (state != previous_state) {
        transition_detected = true;
        previous_state = state;
      }

      // Low frequency reader reports state changes and clears flag
      if (!((high_freq_index + 1) % 5)) {
        std::cout << (transition_detected ? high : previous_state);
        transition_detected = false;
      }

      ++high_freq_index;
    }

    std::cout << " actual\n";
  }
}

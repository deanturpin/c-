#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// {0b11111'11111'11111'11111'11111, 0b01111}, // All bits set
// {0b00000'00000'00000'00000'00000, 0b00000}, // No bits set
// {0b10101'01010'10101'01010'00000, 0b01110}, // Alternate
// {0b00011'11111'00000'00000'00000, 0b01100}, // Block
// {0b00011'11111'11100'00000'00000, 0b01100}, // Block
// {0b00000'11111'11111'10000'00000, 0b01100}, // Block
// {0b10001'00000'00000'01000'00000, 0b01000}, // Random

int main() {

  // A test consists of a pair of input and output bitsets, the low frequency
  // reader runs first
  const std::vector<std::tuple<std::string, std::string, std::string>>
      test_cases{
          // 0123|0123|0123|0123|0123|   expected actual
          {"-------------------------", "-----", ""},
          {"_________________________", "_____", ""},
          {"_____-----------_________", "_---_", ""},
          {"___________--------------", "__---", ""},
          {"-_-_-_-_-_-_-_-_-_-_-_-_-", "-----", ""},
          // 0123|0123|0123|0123|0123|
      };

  // const auto blah = std::make_tuple(0, 1, 2);
  // const auto rah = std::make_tuple(10, "Test", 3.14);

  std::cout << test_cases.size() << " test cases\n";

  // Iterate over each test pair
  for (const auto & [ input, expected, actual ] : test_cases) {

    // for (const auto &bit : input)
    //         std::cout << bit;
    // std::cout << "\n";
    for (const auto &v : {input, expected, actual})
      std::cout << std::quoted(v) << '\n';

    //     // Register used by both low- and high-frequency readers
    //     bool event_detected_flag = false;
    //     bool transition_detected = false;
    //
    //     // The low frequency reader is called less often
    //     const auto low_frequency_reader = [&event_detected_flag,
    //     &transition_detected]() {
    //
    // 	    bool val = false;
    //
    // 	    if (transition_detected) {
    // 		    // std::cout << "transition_detected\n";
    // 		    transition_detected = false;
    // 		    val = true;
    // 	    }
    // 	    else
    // 		    val = event_detected_flag;
    //
    // 	    // std::cout << val << " val\n";
    // 	    return val;
    //     };
    //
    //     // The high frequency reader process every state change
    //     const auto high_frequency_reader =
    //         [&event_detected_flag, &transition_detected]
    // 	(const bool event_detected_register) {
    //
    // 	// Check if this is a state transition
    //           if (event_detected_register != event_detected_flag)
    //           transition_detected = true;
    //
    // 	  // Update copy of register
    // 	event_detected_flag = event_detected_register;
    //         };
    //
    //
    //     // Create a container to compare with the expected results from the
    //     test
    //     // case
    //     std::bitset<5> results = 0b0000;
    //     std::stringstream out;
    //
    //     // Iterate over each bit in the input sequence
    //     out << input << " test\n" << output << " expected\n";
    //     size_t result_index = results.size() - 1;
    //     for (size_t i = 0; i < input.size(); ++i) {
    //
    // 	    // std::cout << i << '\n';
    //       // The high-frequency reader sets the shared register for each
    //       input bit
    //       high_frequency_reader(input.test(i));
    //
    //       // The low-frequency reader checks the shared register less often
    //       if ((i % results.size()) == results.size() - 1) {
    // 	      const auto r = low_frequency_reader();
    //
    // 	      // std::cout << result_index << " becomes " << r << "\n";
    //         results[result_index--] = r;
    //       }
    //
    //     }

    // Print results
    //     out << results << " actual\n";
    //     out << (results == output ? "PASS" : "FAIL") << "\n\n";
    //
    //     if (results != output)
    // 	    std::cout << out.str();
  }
}

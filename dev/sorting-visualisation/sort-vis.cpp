#include <algorithm>
#include <iostream>
#include <vector>

int main()
{

    using namespace std;

    // A sequence to sort
    const std::vector<unsigned int> sequence = {
        13, 6, 30, 17, 6, 28, 25, 22, 13, 24, 29, 9, 6, 21, 12, 16, 11, 16, 11, 12,
        1, 31, 3, 15, 12, 10, 18, 11, 13, 28, 10, 28, 21, 5, 27, 22, 12, 26, 24, 8
    };

    // Max element in the sequence
    const auto max = *max_element(sequence.cbegin(), sequence.cend());

    // Print sequence
    const auto print = [&max](const auto& s) {

        static unsigned int calls = 1;

        // Jump to top of screen
        cout << "\033[1;1H";

        // Print sequence
        for_each(s.cbegin(), s.cend(),
            [&max](auto& n) { cout << string(n, ' ') << '|' << string(max - n, ' ') << endl; });

        // Print some stats
        cout << "\nIterations " << calls << string(max, ' ') << endl;
        ++calls;
    };

    // Fill the screen with an empty list to move the cursor to the bottom
    print(vector<unsigned int>(sequence.size()));
    print(sequence);

    ////////////////////
    // Insert sort

    // Define the algorithm
    const auto insertionSort = [&print](auto& s) {

        for (auto i = s.begin(); i != s.end() - 1; ++i) {

            auto now = i;
            auto next = (now + 1);

            if (*next < *now) {

                // Swap element
                const auto t = *now;
                *now = *next;
                *next = t;

                // Return to start
                i = s.begin();
            }

            print(s);
        }
    };

    // Create a copy and sort
    auto s1(sequence);
    insertionSort(s1);

    return 0;
}

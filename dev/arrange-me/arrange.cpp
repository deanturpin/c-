#include <algorithm>
#include <iostream>
#include <vector>

int main()
{

    using namespace std;

    const vector<unsigned int> packets = {

        0, 17, 11, 23, 21, 32, 30, 16, 6, 16, 18, 5, 9, 9, 32, 21, 3, 4, 31, 6, 31,
        28, 21, 29, 2, 3, 12, 9, 24, 7, 13, 32, 32, 16, 5, 28, 28, 2, 13, 31, 4, 19,
        17, 4, 25, 27, 21, 22, 6, 15, 13, 11, 32, 18, 32, 16, 4, 1, 9, 10, 3, 12, 4,
        14, 16, 25, 22, 14, 14, 28, 15, 0, 32, 29, 7, 4, 18, 8, 15, 28, 25, 18, 18,
        24, 27, 18, 21, 21, 6, 17, 12, 1, 2, 6, 32, 14, 31, 30, 19, 16, 3, 16, 13,
        18, 2, 31, 21, 0, 25, 10, 31, 16, 7, 4, 28, 0, 25, 32, 32, 28, 3, 4, 31, 25,
        23, 3, 26, 13, 6, 7, 1, 31, 0, 28, 11, 5, 9, 20, 29, 19, 27, 14, 12, 0, 32,
        0, 7, 26, 2, 27, 25, 4, 30, 25, 30, 23, 32, 2, 8, 5, 15, 28, 7, 24, 3, 0, 0,
        17, 17, 25, 1, 13, 18, 5, 29, 23, 13, 19, 31, 22, 32, 6, 31, 14, 2, 6, 24,
        23, 11, 20, 22, 25, 22, 16, 28, 9, 4, 24, 17, 21
    };

    // Make a copy of packets to filter
    auto filtered(packets);

    // Filter
    auto it = copy_if(packets.begin(), packets.end(), filtered.begin(),
        [](auto& n) { return n < 4; });

    // Truncate the end bit
    filtered.resize(
        distance(
            filtered.begin(),
            it));

    // Print the result
    cout << "filtered " << filtered.size() << endl;
    for_each(filtered.cbegin(), filtered.cend(),
        [](auto& n) { cout << n << endl; });

    return 0;
}

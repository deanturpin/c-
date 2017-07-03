#include <iostream>

void nonmember_begin_and_end()
{
    using namespace std;

    // Create lambda to square a parameter
    auto square = [](const int n) { return n * n; };

    int array[] = { 1, 2, 3 };

    // For each
    for (const auto& a : array)
        cout << square(a) << endl;

    // Non-member
    for (auto i = begin(array); i != end(array); ++i)
        cout << *i << endl;
}

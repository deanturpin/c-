#include <iostream>
#include <map>
#include <sstream>

int main()
{
    using namespace std;

    // Read complete file on stdin
    stringstream file;
    file << cin.rdbuf();

    cout << "File is " << file.str().size() << endl;

    map<char, int> histogram;

    // Frequency analysis
    for (auto c : file.str())
        ++histogram[c];

    cout << "Histogram size " << histogram.size() << endl;

    for (auto h : histogram)
        cout << static_cast<int>(h.first) << "\t" << h.second << endl;

    return 0;
}

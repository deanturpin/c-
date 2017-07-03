#include <exception>
#include <iostream>
#include <vector>

int main()
{
    using namespace std;

    // Simple
    try {
        throw 2;
    } catch (int e) {
        cout << "Caught exception " << e << endl;
    }

    try {
        vector<int> vec(-1);
    } catch (exception& e) {
        cout << "Standard exception " << e.what() << endl;
    }

    return 0;
}

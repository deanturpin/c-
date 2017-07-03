#include <fstream>
#include <iostream>

int main()
{

    using namespace std;

    cout << "Random noise" << endl;

    // Source of random data
    const string randomFile = "/dev/urandom";
    cout << "Using " << randomFile << endl;

    // Read some
    int blah;
    ifstream(randomFile).read(reinterpret_cast<char*>(&blah), sizeof blah);

    cout << "Read " << blah << endl;

    return 0;
}

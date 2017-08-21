#include <iostream>

int main() {

    using namespace std;

    try { throw("ball"); }
    catch (string name) { cout << "Caught " << name << endl; }

    return 0;
}

#include <iostream>
#include <vector>

#include "pxl.h"
#include "riff.h"
#include "unistd.h"

int main()
{

    using namespace std;

    // Read header
    riff::header h;
    cin.read(reinterpret_cast<char*>(&h), sizeof h);

    // Read samples
    const unsigned int total = h.data.size;
    vector<short> samples(total);
    cin.read(reinterpret_cast<char*>(samples.data()), samples.size() * sizeof(short));

    // Create bitmap
    pxl::pxl8 p;

    // Target dimensions
    const int x = p.width();
    const int x_bin_size = samples.size() / x;

    // Populate
    for (const auto& s : samples) {

        static int i = 0;
        p.set(i++ / x_bin_size, p.height() / 2 + s / 1000);
    }

    p.render();

    sleep(5);

    return 0;
}

#include "pxl.h"
#include "riff.h"
#include "unistd.h"
#include <iostream>
#include <vector>

int main()
{
    using namespace std;

    // Read header
    riff::header h;
    cin.read(reinterpret_cast<char*>(&h), sizeof h);

    // Create bitmap
    pxl::pxl8 p;

    // Read samples
    const unsigned int batch = p.width() * 2;
    vector<short> samples(batch);

    while (cin.read(reinterpret_cast<char*>(samples.data()), batch * sizeof(short))) {
        // Store every other sample (two channels)
        for (auto s = samples.cbegin(); s != samples.cend(); s += 2)
            p.set(distance(samples.cbegin(), s) / 2, (p.height() / 2) + *s / 1000);

        // Render the buffer
        p.render();

        usleep(27000);
    }

    return 0;
}

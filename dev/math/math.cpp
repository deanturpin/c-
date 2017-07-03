#include "pxl.h"
#include <cmath>
#include <unistd.h>

int main()
{
    using namespace std;

    // Create a bitmap
    pxl::pxl8 p;

    for (int i = 0; i < 180; ++i) {
        // Generate a sine wave
        for (int j = 0; j < 360; ++j) {
            const auto x = static_cast<unsigned int>(round(p.width() * j / 360.0));
            const auto y = static_cast<unsigned int>(round(p.height() / 2 + p.height() / 2 * sin(M_PI * (j + i) / 180.0)));

            p.set(x, y);
        }

        p.render();
        usleep(50000);
    }

    return 0;
}

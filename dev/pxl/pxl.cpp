#include "pxl.h"
#include "unistd.h"

int main()
{
    // Create bitmap
    pxl::pxl8 p;

    // Draw some dots
    p.set(26, 29);
    p.set(28, 23);
    p.set(42, 23);
    p.set(50, 27);
    p.set(50, 31);
    p.set(46, 35);
    p.set(37, 41);
    p.set(33, 43);
    p.set(28, 48);
    p.set(27, 49);
    p.set(26, 50);
    p.set(25, 50);
    p.set(24, 49);
    p.set(23, 48);
    p.set(19, 44);
    p.set(15, 41);
    p.set(5, 35);
    p.set(2, 31);
    p.set(2, 27);
    p.set(9, 23);
    p.set(18, 23);
    p.set(24, 26);

    // Render and pause
    p.render();
    sleep(10);

    return 0;
}

#include <iostream>
#include <vector>

namespace flood

{

using namespace std;

std::vector<std::string> bitmap = {

    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
    "                          ",
};

const unsigned int width = bitmap.front().size();
const unsigned int height = bitmap.size();

void dump()
{

    cout << width << ", " << height << endl;

    for (const auto& raster : bitmap)
        cout << raster << endl;
}

unsigned int callCounter = 0;

bool fill(const unsigned int x, const unsigned int y)
{

    ++callCounter;

    // Check range
    if (x >= width || y >= height) {

        // cout << "Start point out of range: " << x << ", " << y << endl;
        return false;
    }

    // Check start point and set it
    if (bitmap[y][x] != 'x') {

        bitmap[y][x] = 'x';

        // Fill surrounding points
        fill(x, y + 1);
        fill(x, y - 1);
        fill(x + 1, y);
        fill(x - 1, y);
    }

    return true;
}
}

int main()
{

    // Print starting state
    flood::dump();

    // Print if flood fill is successful
    if (flood::fill(0, 0))
        flood::dump();

    std::cout << "Point " << flood::width * flood::height << std::endl;
    std::cout << "Calls " << flood::callCounter << std::endl;

    return 0;
}

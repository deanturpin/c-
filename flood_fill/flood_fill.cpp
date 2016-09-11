#include <iostream>
#include <vector>

namespace flood {

	using namespace std;

	std::vector<std::string> bitmap = {

		"                          ",
		"                          ",
		"  xxxxxxxxxxxxxxx         ",
		"  x              x        ",
		"  x              x        ",
		"   xx            x        ",
		"     x    xxxxxxx         ",
		"      x    x              ",
		"       x    x             ",
		"        xxxxx             ",
		"                          ",
		"             xxxx         ",
	};

	const unsigned int width = bitmap.front().size();
	const unsigned int height = bitmap.size();

	void dump() {

		cout << width << ", " << height << endl;

		for (const auto &raster : bitmap)
			cout << raster << endl;
	}

	bool fill(const unsigned int x, const unsigned int y) {

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

int main() {

	// Print starting state
	flood::dump();

	// Print if flood fill is successful
	if (flood::fill(2, 10))
		flood::dump();
	
	return 0;
}

#include <iostream>
#include <vector>

namespace flood {

	using namespace std;

	std::vector<std::string> bitmap = {
		"x       xxxxxxxxxxxxxxx         ",
		"        x              x        ",
		"        x              x        ",
		"        x              x        ",
		"         x             x        ",
		"          xxxxxx       x        ",
		"                x      x        ",
		"                 x     x        ",
		"                  x    x        ",
		"                   xxxx         ",
		"                                ",
		"                                ",
		"                                ",
		"                                ",
		"                   xxxx         ",
	};

	void dump() {
	
		// Top and bottom border
		const string border = "\t" + string(bitmap.front().size() + 1, '_');
		cout << border << endl;

		const unsigned int width = bitmap.size();
		const unsigned int height = bitmap.front().size();

		for (unsigned int w = 0; w < width; ++w) {
			cout << w << "\t|";

			for (unsigned int h = 0; h < height; ++h)
				cout << bitmap[w][h];

			cout << "|" << endl;
		}
				
		cout << border << endl;
	}

	bool fill(const int x, const int y) {

		// cout << "Start point " << x << ", " << y << endl;

		// Check range
		if (x < 0 || y < 0 || x > bitmap.front().size() || y > bitmap.size()) {
			
			cout << "Start point out of range: " << x << ", " << y << endl;
			return false; 
		}

		// Check start point
		if (bitmap[x][y] != 'x') {

			bitmap[x][y] = 'x';

			fill(x + 1, y + 1);
			fill(x + 1, y);
			// fill(x + 1, y - 1);

			fill(x - 1, y + 1);
			fill(x - 1, y);
			fill(x - 1, y - 1);

			fill(x, y + 1);
			fill(x, y - 1);
		}

		return true;
	}
}

int main() {

	// Print starting state
	flood::dump();

	// Print if flood fill is successful
	if (flood::fill(2, 15))
		flood::dump();
	
	return 0;
}

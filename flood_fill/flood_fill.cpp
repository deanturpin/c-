#include <iostream>
#include <vector>

namespace flood {

	using namespace std;

	std::vector<std::string> bitmap = {
		"x                               ",
		"        xxxxxxxxxxxxxxx         ",
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
		"                                "
	};

	void dump() {
	
		// Top and bottom border
		const string border = string(bitmap.front().size() + 2, '_');
		cout << border << endl;

		for (const auto &raster : bitmap) {

			cout << "|";

			for (const auto &c : raster)
				cout << c;

			cout << "|" << endl;
		}

		cout << border << endl;
	}

	bool fill(const unsigned int x, const unsigned int y) {

		cout << "Start point " << x << ", " << y << endl;

		// Check range
		if (x > bitmap.front().size() || y > bitmap.size()) {
			
			cout << "Start point out of range" << endl;
			return false; 
		}

		// Check start point
		cout << (bitmap[x][y] == 'x' ? "Bad " : "Good") << " start" << endl;
		cout << '\"' << bitmap[x][y] << '\"' << endl;

		return true;
	}
}

int main() {

	// Print starting state
	flood::dump();

	// Print if flood fill is successful
	if (flood::fill(8, 0))
		flood::dump();
	
	return 0;
}

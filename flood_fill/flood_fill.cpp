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
		const string border = string(bitmap.front().size() + 2, '.');
		cout << border << endl;

		for (const auto &raster : bitmap)
			cout << '.' << raster << '.' << endl;

		cout << border << endl;
	}

	bool fill(const unsigned int x, const unsigned int y) {

		cout << "Start at " << x << ", " << y << endl;

		// Check range
		if (x > bitmap.front().size() || y > bitmap.size()) {
			
			cout << "Start point out of range" << endl;
			return false; 
		}

		// Check start point
		if (bitmap[x][y] == 'x')
			cout << "Bad start point" << endl;
		else
			cout << "Good start point" << endl;

		return true;
	}
}

int main() {

	flood::dump();
	flood::fill(8, 0);
	flood::dump();
	
	return 0;
}

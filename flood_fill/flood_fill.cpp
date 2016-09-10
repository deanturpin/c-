#include <iostream>
#include <vector>

namespace flood {

	using namespace std;

	std::vector<std::string> bitmap = {

		"                                ",
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
		
		for (const auto &raster : bitmap)
			cout << raster << endl;
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
	flood::fill(10, 10);
	flood::fill(8, 1);
	flood::dump();
	
	return 0;
}

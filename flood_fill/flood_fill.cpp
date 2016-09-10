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

	void fill(const unsigned int x, const unsigned int y) {

		cout << "Start at " << x << ", " << y << endl;

		// Check range
		if (x > bitmap.front().size() || y > bitmap.size()) {
			
			cout << "Start point out of range" << endl;
			return;
		}
	}
}

int main() {

	flood::dump();
	flood::fill(6, 7);
	flood::fill(100, 1000);
	flood::dump();
	
	return 0;
}

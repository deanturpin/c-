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

	void fill(const int x, const int y) {
		cout << "Start at " << x << ", " << y << endl;
	}
}

int main() {

	flood::fill(6, 7);
	
	return 0;
}

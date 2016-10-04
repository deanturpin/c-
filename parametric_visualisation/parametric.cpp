#include <iostream>
#include <vector>


int main() {

	using namespace std;

	const unsigned int X = 75;
	const unsigned int Y = 40;

	// Create an empty raster
	vector<bool> raster(X, false);

	// Initialise bitmap
	vector<vector<bool>> bitmap(Y, raster);

	// Some params
	struct P {

		unsigned int x;
		unsigned int y;
		unsigned int z;
	};

	vector<P> params = {
		{0, 1, 2},
		{0, 2, 2},
		{0, 3, 2},
		{0, 4, 3},
		{2, 1, 3},
		{2, 1, 3},
		{2, 1, 3},
	};

	// Populate bitmap
	for (const auto &p : params)
		bitmap[p.x][p.y] = true;

	// Print bitmap

	for (const auto &y : bitmap) {

		for (const auto x : y)
			cout << (0 == x ? ' ' : '.');

		cout << '|' << endl;
	}
	cout << string(X, '_') << '|'<< endl;

	return 0;
}

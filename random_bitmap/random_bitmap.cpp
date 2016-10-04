#include <iostream>
#include <vector>

int main() {

	using namespace std;

	const unsigned int X = 50;
	const unsigned int Y = 20;

	// Create an empty raster
	vector<bool> raster(X, false);

	// Initialise bitmap
	vector<vector<bool>> bitmap(Y, raster);

	// Scribble
	for (int i = 0; i < 10; ++i)
		bitmap[i][i] = 1;

	const string rule(X + 2, '-');
	cout << rule << endl;

	// Print bitmap
	for (const auto &y : bitmap) {

		cout << '|';

		for (const auto &x : y)
			cout << (0 == x ? ' ' : '0');

		cout << '|' << endl;
	}

	cout << rule << endl;

	return 0;
}

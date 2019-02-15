#include <iostream>

int main() {

	int x = 10;
	int &y = x;
	auto z = y;

	y = 20;

	std::cout << x << '\n';
	std::cout << y << '\n';
	std::cout << z << '\n';
}

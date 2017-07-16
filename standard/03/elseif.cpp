#include <iostream>

int main()
{
    int i = -1;

    int b =
			i == 1 ? 1 :
			i == 2 ? 2 :
			i == 3 ? 3 :
			i == 4 ? 4 : 5;

    std::cout << "b is " << b << std::endl;

    // Is equivalent to

    int c = 0;

    if (i == 1)
        c = 1;
    else if (i == 2)
        c = 2;
    else if (i == 3)
        c = 3;
    else if (i == 4)
        c = 4;
    else
        c = 5;

    std::cout << "c is " << b << std::endl;

		return 0;
}

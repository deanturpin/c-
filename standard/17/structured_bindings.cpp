#include <iostream>

struct S {

    int i = 4;
    int j = 5;
};

int main()
{

    auto[i, j] = S();

    return 0;
}

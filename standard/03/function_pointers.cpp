#include <iostream>

void foo()
{
    std::cout << "foo" << std::endl;
}

int bar(const double& b)
{
    std::cout << "bar " << b << std::endl;
    return 0;
}

int multiply(int a, int b)
{
    return a * b;
}

int operation(int a, int b, int (*func)(int, int))
{
    return func(a, b);
}

int main()
{
    // Function pointer as an alias
    void (*f)(void) = foo;
    int (*b)(const double&) = bar;

    (*f)();
    f();
    b(0.0);

    // Pass into a function
    std::cout << operation(4, 5, multiply) << std::endl;

    return 0;
}

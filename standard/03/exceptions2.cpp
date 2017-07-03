// https://pbs.twimg.com/media/CqV-Cx5VYAA6my0.jpg

#include <iostream>

void toss(const std::string& name)
{

    throw name;
}

int main()
{

    using namespace std;

    try {

        toss("ball");
    }

    catch (string name) {

        cout << "Caught " << name << endl;
    }

    return 0;
}

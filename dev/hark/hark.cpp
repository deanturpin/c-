#include <vector>
// #include <random>
#include <iostream>

int main()
{
    using namespace std;

    // Populate replies
    vector<string> replies;
    replies.push_back("Drink!");
    replies.push_back("Chair... curtains... floor...");
    replies.push_back("Gobshite!");
    replies.push_back("What? Priests? Don't tell me I'm still on that feckin' island!");

    cout << "Number of replies " << replies.size() << endl;

    for (const auto& r : replies)
        cout << r << endl;

    // std::default_random_engine generator;
    // std::uniform_int_distribution<int> distribution(0, replies.size() - 1);
    // int i = distribution(generator);

    return 0;
}

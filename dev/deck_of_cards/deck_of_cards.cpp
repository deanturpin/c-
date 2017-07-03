#include <iostream>
#include <vector>

namespace deck {

using namespace std;

class cards {

    const vector<string> suit = { "hearts", "spades", "clubs", "diamonds" };
    const vector<string> face = { "1", "2", "J", "Q", "K" };

    vector<pair<string, string> > c;

public:
    // Initialise deck
    cards()
    {

        for (const auto& f : face)
            for (const auto& s : suit)
                c.push_back(make_pair(f, s));
    }

    // Print each card
    void dump()
    {

        for (const auto& card : c)
            cout << card.first << " " << card.second << endl;
    }
};
}

int main()
{

    deck::cards d;
    d.dump();

    return 0;
}

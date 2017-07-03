#include <bitset>
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    // Normal string
    {
        cout << "Normal strings \"\u2764\"" << endl;

        string codepoint("\u2764");
        cout << "cout \"" << codepoint << "\"" << endl;

        for (auto x : codepoint)
            cout << hex << static_cast<int>(x) << dec << endl;
    }

    // Wide string
    {
        cout << "\nWide strings \"\u2764\"" << endl;

        wstring codepoint(L"\u2765");
        wcout << "wcout \"" << codepoint << "\"" << endl;

        for (auto x : codepoint)
            cout << hex << static_cast<int>(x) << dec << endl;
    }

    // Digit representation
    auto int_rep = 1 '000' 000;
    auto hex_rep = 0x0123 '4567' 89ab'cdef; auto bin_rep = 0b0000 '1111' 0000'1111;

        cout
        << int_rep << endl;
    cout << hex << hex_rep << endl;
    cout << std::bitset<16>(bin_rep) << endl;

    return 0;
}
